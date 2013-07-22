#include <OGDT/script.h>
#include <OGDT/Exception.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <sys/wait.h>

using namespace OGDT;

struct ScriptLoader::impl
{
    PluginManager plugin_manager;
    
    std::vector<std::string> flags;
    std::vector<const char*> cflags; // To avoid using new in 'get' function.
    std::string compiler;
    
    impl () : compiler("g++") {
        flags.push_back("-fPIC");
    }
};

ScriptLoader::ScriptLoader () : my(new impl) {}

ScriptLoader::~ScriptLoader () {
    delete my;
}

void ScriptLoader::addFlag (const char* flag) {
    my->flags.push_back(flag);
    my->cflags.resize(my->cflags.size()+1);
}

void ScriptLoader::addIncludePath (const char* path) {
    my->flags.push_back(std::string(" -I") + path);
    my->cflags.resize(my->cflags.size()+1);
}

bool exec (std::string& output, const char* cmd, char* const args[]) {
    static const int EXEC_ERROR = 117;
    int p[2];
    if (pipe(p) != 0) {
        output = "pipe() failed";
        return false;
    }
    pid_t pid = fork();
    // Close end of pipe we aren't concerned with, otherwise EOF
    // is never returned when reading from the child.
    if (pid == 0) {
        close(p[0]);
        dup2(p[1], 1);
        dup2(p[1], 2);
        close(p[1]);
        int result = execvp(cmd, args);
        fprintf(stderr, "Failed running %s, exec returned %d\n", cmd, result);
        exit(EXEC_ERROR);
    }
    else if (pid >= 0) {
        close(p[1]);
        int stat;
        int result = waitpid(pid, &stat, 0);
        if (result == -1) {
            output = "waitpid() failed";
            close(p[0]);
            return false;
        }
        int exit_code = WEXITSTATUS(stat);
        if (!WIFEXITED(stat)) {
            output = "process did not exit normally";
            close(p[0]);
            return false;
        }
        if (exit_code != 0 && exit_code != EXEC_ERROR) {
            output = std::string("process exited with error code ")
                   + std::to_string(exit_code) + ". Error:\n";
        }
        else output = "";
        char buf[128];
        ssize_t bytes;
        while ((bytes = read(p[0], buf, 127)) > 0) {
            buf[bytes] = 0;
            output = output + std::string(buf, bytes);
        }
        if (bytes == -1) {
            output = "read() failed";
            return false;
        }
        close(p[0]);
        return exit_code == 0;
    }
    else {
        close(p[0]);
        close(p[1]);
        output = "fork() failed";
        return false;
    }
}

void fill_flags
    (const std::vector<std::string>& flags, std::vector<const char*>& cflags) {
    for (const std::string& s : flags) cflags.push_back(s.c_str());
}

Plugin ScriptLoader::get (const char* name, const char* code) {
    using namespace std;
    
    // Write code to file.
    string file_name = string(name) + ".cc";
    ofstream file(file_name);
    file << code;
    file.close();
    
    // Compile library.
    string output;
    std::vector<const char*>& cflags = my->cflags;
    cflags.clear();
    cflags.push_back(my->compiler.c_str());
    fill_flags(my->flags, cflags);
    cflags.push_back("-c");
    string cc = string(name) + ".cc";
    cflags.push_back(cc.c_str());
    cflags.push_back(NULL);
    bool success = exec(output, my->compiler.c_str(), (char* const*)&cflags[0]);
    if (success) {
        // Link.
        string object = string(name) + ".o";
        string so = string("lib") + name + ".so";
        cflags.clear();
        cflags.push_back(my->compiler.c_str());
        cflags.push_back("-shared");
        cflags.push_back(object.c_str());
        cflags.push_back("-o");
        cflags.push_back(so.c_str());
        cflags.push_back(NULL);
        success = exec(output, my->compiler.c_str(), (char* const*)&cflags[0]);
        if (success) {
            // Load the library and return a plugin.
            string library_path = string(name);
            return my->plugin_manager.get(library_path.c_str());
        }
        else {
            ostringstream os;
            os << "Failed linking script " << name << ":" << endl
               << output;
            throw EXCEPTION(os);
        }
    }
    else {
        ostringstream os;
        os << "Failed compiling script " << name << ":" << endl
           << output;
        throw EXCEPTION(os);
    }
}
