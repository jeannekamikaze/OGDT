#pragma once

#ifdef WIN32
	#ifdef OGDT_EXPORT
	#define DECLDIR __declspec(dllexport)
	#elif OGDT_STATIC
	#define DECLDIR
	#else
	#define DECLDIR __declspec(dllimport)
	#endif
#else
	#define DECLDIR
#endif
