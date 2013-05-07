#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/*
  File: guicon
*/

/*
  Function: open_console
  Open a console.

  Parameters:

  console_lines - The number of lines in the console buffer. 0 for default value (1024).

  This function opens a console in debug builds of OGDT and does nothing in release builds.

  This function is especially useful when developing WIN32 applications,
  where there is no console by default.
*/
void open_console (int console_lines);

#ifdef __cplusplus
}
#endif
