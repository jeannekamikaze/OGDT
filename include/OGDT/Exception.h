#pragma once

#include <exception>
#include <sstream>

namespace OGDT
{

/*
Class: Exception
A framework exception.
*/
class Exception : public std::exception
{
public:

    ~Exception () throw () {}

    /*
      Constructor: Exception
      Build an exception from a C char string.
    */
    Exception (const char* what) throw ();

    /*
      Constructor: Exception
      Build an exception from an ostringstream.
    */
    Exception (const std::ostringstream& what) throw ();

    /*
      Constructor: Exception
      Build an exception from a C char string and file/line information.
    */
    Exception (const char* file, int line, const char* what) throw ();

    /*
      Constructor: Exception
      Build an exception from an ostringstream and file/line information.
    */
    Exception (const char* file, int line, const std::ostringstream& what) throw ();

    /*
      Function: what
      Return the exception's message.
    */
    const char* what () const throw ();
};

#define EXCEPTION(what) Exception(__FILE__, __LINE__, what)

} // namespace OGDT
