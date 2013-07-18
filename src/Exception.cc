#include <OGDT/Exception.h>
#include <cstdio>
#include <sstream>

#ifdef _MSC_VER
#define snprintf _snprintf
#endif

#define EXP_SIZE 1024

#ifdef WIN32
    #define TLS __declspec( thread )
#else
    #define TLS __thread
#endif

TLS char exp_buf[EXP_SIZE];

using namespace OGDT;
using namespace std;


Exception::Exception (const char* what) throw ()
{
    snprintf (exp_buf, EXP_SIZE, "%s", what);
}


Exception::Exception (const std::ostringstream& what) throw ()
{
    snprintf (exp_buf, EXP_SIZE, "%s", what.str().c_str());
}


Exception::Exception (const char* file, int line, const char* what) throw ()
{
    snprintf (exp_buf, EXP_SIZE, "File: %s, line: %d: %s", file, line, what);
}


Exception::Exception (const char* file, int line, const std::ostringstream& what) throw ()
{
    snprintf (exp_buf, EXP_SIZE, "File: %s, line: %d: %s", file, line, what.str().c_str());
}


const char* Exception::what () const throw ()
{
    return exp_buf;
}
