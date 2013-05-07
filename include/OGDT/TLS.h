#pragma once

#ifdef WIN32
    #define TLS __declspec( thread )
#else
    #define TLS __thread
#endif

