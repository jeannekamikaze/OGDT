#pragma once

#include <stdint.h>

/*
File: Types
*/

#if defined(__GNUC__) || defined(__GNUG__) //Compiling with GNU C/C++ compiler
    typedef __INT8_TYPE__    I8;
    typedef __INT16_TYPE__    I16;
    typedef __INT32_TYPE__    I32;
    typedef __INT64_TYPE__    I64;
    typedef __UINT8_TYPE__    U8;
    typedef __UINT16_TYPE__    U16;
    typedef __UINT32_TYPE__    U32;
    typedef __UINT64_TYPE__    U64;
#else //Visual Studio
    /*
    Typedef: I8
    A signed 8-bit integer.
    */
    typedef __int8    I8;
    /*
    Typedef: I16
    A signed 16-bit integer.
    */
    typedef __int16    I16;
    /*
    Typedef: I32
    A signed 32-bit integer.
    */
    typedef __int32 I32;
    /*
    Typedef: I64
    A signed 64-bit integer.
    */
    typedef __int64 I64;
    /*
    Typedef: I8
    An unsigned 8-bit integer.
    */
    typedef unsigned __int8        U8;
    /*
    Typedef: I16
    An unsigned 16-bit integer.
    */
    typedef unsigned __int16    U16;
    /*
    Typedef: I32
    An unsigned 32-bit integer.
    */
    typedef unsigned __int32    U32;
    /*
    Typedef: I64
    An unsigned 64-bit integer.
    */
    typedef unsigned __int64    U64;
#endif
