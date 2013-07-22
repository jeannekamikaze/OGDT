#pragma once

namespace OGDT
{

class Plugin;

/*
Typedef: fptr
A pointer to a function.
*/
typedef void* (*fptr)(...);

/*
Class: PluginManager
Manages plugins.
*/
class PluginManager
{
    struct impl;
    impl* my;
    
    PluginManager (const PluginManager&);
    PluginManager& operator= (const PluginManager&);
    
public:
    
    /*
    Constructor: PluginManager
    */
    PluginManager();
    
    /*
    Destructor: ~PluginManager
    */
    ~PluginManager();
    
    /*
    Function: get
    Load a plugin for the first time, or get an existing plugin if it
    has already been loaded.
    
    Parameters:
    
    plugin_path - Path to the plugin to be loaded, with no file extension.
    On Linux, the 'lib' prefix must also be discarded.
    
    Throws:
    
    OGDT::Exception - Plugin file not found.
    */
    Plugin get (const char* plugin_path);
    
    /*
    Function: reload
    Reload the plugin.
    
    Parameters:
    
    plugin_path - Path to the plugin to be reloaded, with no file extension.
    On Linux, the 'lib' prefix must also be discarded.
    
    Throws:
    
    OGDT::Exception - Plugin file not found.
    */
    void reload (const char* plugin_path);
    
    /*
    Function: resolve
    Resolve and return a pointer to a function in a plugin.
    
    Parameters:
    
    plugin - The plugin containing the function to be resolved.
    function_name - The function to be resolved.
    
    Throws:
    
    OGDT::Exception - Failed resolving the specified function.
    */
    fptr resolve (const Plugin& plugin, const char* function_name);
};

// Plugin

/*
Class: Plugin
*/
class Plugin
{
    friend class PluginManager;
    
    typedef int* ID;
    
    ID id;
    PluginManager* plugin_manager;
    
    Plugin (ID _id, PluginManager* m) : id(_id), plugin_manager(m) {}

public:
    
    class function
    {
        OGDT::fptr f;
        
        friend class Plugin;
        
        function (OGDT::fptr _f) : f(_f) {}
    
    public:
        
        template <class... T>
        void* operator() (T... args) {
            (*f)(args...);
        }
    };
        
    /*
    Function: resolve
    Resolve and return a pointer to a function.
    
    Parameters:
    
    function_name - The function to be resolved.
    
    Throws:
    
    OGDT::Exception - Failed resolving the specified function.
    */
    OGDT::fptr resolve (const char* function_name) {
        return plugin_manager->resolve(*this, function_name);
    }
    
    /*
    Operator: ()
    Resolve and return a function.
    
    Parameters:
    
    function_name - The function to be resolved.
    
    Throws:
    
    OGDT::Exception - Failed resolving the specified function.
    */
    Plugin::function operator () (const char* function_name) {
        return function(plugin_manager->resolve(*this, function_name));
    }
};

} // namespace OGDT
