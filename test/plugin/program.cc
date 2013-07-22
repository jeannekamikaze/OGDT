#include <OGDT/plugin.h>
#include <OGDT/Exception.h>
#include <cstdio>

int main ()
{
    try {
        OGDT::PluginManager manager;
        OGDT::Plugin p = manager.get("mylib");
        
        int x = 2;
        
        // Manually resolving and calling
        
        OGDT::fptr square = p.resolve("square");
        int x2 = (int) square(x);
        printf ("%d^2 = %d\n", x, x2);
        
        // Syntactic sugar call
        
        int x3 = (int) p("square")(x);
        printf ("%d^2 = %d\n", x, x3);
        
        // If function fails to resolve, an exception is thrown
        
        (*p.resolve("this_fails_with_exception"))();
        (*p.resolve("this is not executed"))();
    }
    catch (const OGDT::Exception& e) {
        fprintf(stderr, "%s\n", e.what());
    }
    return 0;
}
