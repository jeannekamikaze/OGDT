#pragma once

#include <OGDT/OGDT.h>
#include <OGDT/math/Spatial.h>
#include <OGDT/math/mat4.h>

namespace OGDT
{

/*
Class: Camera
*/
class DECLDIR Camera : public Spatial
{
	mat4 proj;

public:

	/*
	Constructor: Camera
	Construct a perspective camera.
	*/
	Camera (float fovy, float aspect, float near, float far);

	/*
	Constructor: Camera
	Construct an orthographic camera.
	*/
	Camera (float left, float right, float bottom, float top, float near, float far);


	/*
	Function: projection
	Return the camera's projection matrix.
	*/
	const mat4& projection () const { return proj; }
};

} // namespace OGDT

