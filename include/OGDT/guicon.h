#pragma once

#include <OGDT/OGDT.h>

/*
File: guicon
*/

/*
Function: open_console
Open a console.

This function opens a console in debug builds of OGDT and does nothing in release builds.

This function is especially useful when developing WIN32 applications,
where there is no console by default.
*/
DECLDIR void open_console (int console_lines = 1024);
