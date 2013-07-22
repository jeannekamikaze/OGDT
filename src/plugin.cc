#include <OGDT/plugin.h>
#include <OGDT/Exception.h>
#include <dlfcn.h>
#include <unordered_map>
#include <string>
#include <sstream>
#include <cstring>

using namespace OGDT;

// /path/to/file -> /path/to/libfile.so
// file -> ./libfile.so
// empty if bad format
std::string transform_file_path (const char* const name) {
    const char* last = name + strlen(name) - 1;
    const char* p = last;
    while (p >= name && *p != '/') --p;
    if (p < name) return std::string("./lib") + name + ".so";
    p++;
    if (p > last) return "";
    size_t path_len = p-name;
    const char* path = name;
    return std::string(path, path_len) + "lib" + p + ".so";
}

// Represents a shared library.
struct lib
{
    #define assert_handle() { \
        if (handle == NULL) { \
            std::ostringstream os; \
            os << "Failed loading plugin " << plugin_path; \
            throw EXCEPTION(os); \
        } \
    }

public:
    
    typedef void* libhandle;
    typedef std::unordered_map<std::string, OGDT::fptr> function_map;
    
    libhandle handle;
    function_map function; // Cache function addresses for fast access.
    std::string plugin_path;
    
    lib (const char* file_path) : plugin_path(file_path) {
        handle = dlopen(file_path, RTLD_NOW);
        assert_handle();
    }
    
    ~lib () {
        dlclose(handle);
    }
    
    OGDT::fptr resolve (const char* name) {
        // Check cache first, then resolve if function does not exist.
        OGDT::fptr f = function[name];
        if (f == NULL) {
            f = (OGDT::fptr) dlsym(handle, name);
            function[name] = f;
        }
        return f;
    }
    
    void reload () {
        dlclose(handle);
        handle = dlopen(plugin_path.c_str(), RTLD_NOW);
        assert_handle();
    }
    
private:
    
    lib (const lib&);
    lib& operator= (const lib&);
};

struct PluginManager::impl
{
    typedef std::unordered_map<std::string, lib*> library_map;
    typedef std::unordered_map<lib*, Plugin> lib_plugin_map;
    typedef std::unordered_map<Plugin::ID, lib*> plugin_lib_map;
    
    library_map library;
    
    // Every shared library has one and only one associated Plugin.
    lib_plugin_map library_plugin;
    
    // Reverse plugin -> library map for quick access.
    plugin_lib_map plugin_library;
    
    ~impl () {
        for (library_map::value_type& keyval : library) {
            delete keyval.second;
        }
    }
};

PluginManager::PluginManager () : my(new impl) {}

PluginManager::~PluginManager () {
    delete my;
}

Plugin PluginManager::get (const char* plugin_path) {
    // Transform virtual path to native path.
    std::string path = transform_file_path(plugin_path);
    plugin_path = path.c_str();
    // First check that the library has not already been loaded.
    // Load it if necessary and then return a Plugin.
    lib* l = my->library[plugin_path];
    if (l == nullptr) {
        l = new lib(plugin_path);
        my->library[plugin_path] = l;
        Plugin p ((Plugin::ID)l, this);
        my->library_plugin.emplace(l,p);
        my->plugin_library[p.id] = l;
    }
    return my->library_plugin.find(l)->second;
}

void PluginManager::reload (const char* plugin_path) {
    // Transform virtual path to native path.
    std::string path = transform_file_path(plugin_path);
    plugin_path = path.c_str();
    // Reload
    lib* l = my->library[plugin_path];
    if (l == nullptr) get(plugin_path);
    else l->reload();
}

OGDT::fptr PluginManager::resolve
    (const Plugin& plugin, const char* function_name) {
    // plugin_library[&plugin] must exist;
    // plugin ctor/dtor/copy cons is private and friend of PluginManager.
    lib* l = my->plugin_library[plugin.id];
    // Function not found -> set the plugin as unusable,
    // which makes it ignore every further function call.
    fptr f = l->resolve(function_name);
    if (f) return f;
    else {
        std::ostringstream os;
        os << "Failed resolving function " << function_name
           << " in library " << l->plugin_path;
        throw EXCEPTION(os);
    }
}
