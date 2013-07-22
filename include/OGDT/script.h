#pragma once

#include "plugin.h"

namespace OGDT
{

class ScriptLoader
{
    struct impl;
    impl* my;
    
    ScriptLoader (const ScriptLoader&);
    ScriptLoader& operator= (const ScriptLoader&);
    
public:
    
    ScriptLoader ();
    
    ~ScriptLoader ();
    
    void addFlag (const char* flag);
    
    void addIncludePath (const char* path);
    
    void setCompilerPath (const char* path);
    
    Plugin get (const char* name, const char* code);
};

} // namespace OGDT
