#pragma once

#include <exception>
#include <sstream>

namespace OGDT
{

/*
Class: Exception
*/
class Exception : public std::exception
{
public:

    ~Exception () throw () {}

    Exception (const char* what) throw ();

    Exception (const std::ostringstream& what) throw ();

    Exception (const char* file, int line, const char* what) throw ();

    Exception (const char* file, int line, const std::ostringstream& what) throw ();

    /*
    Function: what
    Return the exception's message.
    */
    const char* what () const throw ();
};

#define EXCEPTION(what) Exception(__FILE__, __LINE__, what)

} // namespace OGDT
