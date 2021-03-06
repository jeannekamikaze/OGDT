#include <OGDT/script.h>
#include <OGDT/Exception.h>
#include <cstdio>
#include "Foo.h"

int main ()
{
    try {
        OGDT::ScriptLoader loader;
        
        // Square of a number
        
        const char math_code[] =
            "extern \"C\" {\n"
            "int square (int x) {\n"
            "    return x*x;\n"
            "}\n"
            "}\n";
        
        OGDT::Plugin p = loader.get("math", math_code);
        int x = 2;
        int x2 = p("square")(x);
        printf("%d^2 = %d\n", x, x2);
        
        // A subclass
        
        const char bar_code[] =
            "#include \"Foo.h\"\n"
            "#include <cstdio>\n"
            "class Bar : public Foo {\n"
            "public:\n"
            "    void greet () { printf(\"Bar\\n\"); }\n"
            "};\n"
            "extern \"C\" {\n"
            "Foo* new_foo () { return new Bar; }\n"
            "}\n";
        
        OGDT::Plugin p2 = loader.get("bar", bar_code);
        Foo* foo = (Foo*) p2("new_foo")();
        foo->greet(); // Bar
        delete foo;
        
        // This throws the following exception:
        //
        // OGDT/src/script.cc, line: 154: Failed compiling script baz:
        // process exited with error code 1. Error:
        // baz.cc: In member function ‘virtual void Baz::greet()’:
        // baz.cc:5:36: error: ‘print2f’ was not declared in this scope
        
        const char baz_code[] =
            "#include \"Foo.h\"\n"
            "#include <cstdio>\n"
            "class Baz : public Foo {\n"
            "public:\n"
            "    void greet () { print2f(\"Baz\\n\"); }\n"
            "};\n"
            "extern \"C\" {\n"
            "Foo* new_foo () { return new Baz; }\n"
            "}\n";
        
        loader.get("baz", baz_code);
    }
    catch (const OGDT::Exception& e) {
        fprintf(stderr, "%s\n", e.what());
    }
    return 0;
}
