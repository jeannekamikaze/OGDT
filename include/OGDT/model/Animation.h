#pragma once

#include <OGDT/OGDT.h>

namespace OGDT
{

/*
Struct: Animation
A model animation.
*/
struct DECLDIR Animation
{
	/*
	Variable: name
	The animation's name.
	*/
	const char* name;

	/*
	Variable: duration
	The animation's duration in seconds.
	*/
	float duration;

	/*
	Variable: id
	The animation's id.
	*/
	const unsigned id;

	Animation (const char* _name, float d, const unsigned _id)
		: name (_name), duration (d), id (_id)
	{
	}
};

} // namespace OGDT
