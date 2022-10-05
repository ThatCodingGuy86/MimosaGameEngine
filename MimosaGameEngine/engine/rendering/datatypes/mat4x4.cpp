#pragma once
#include "mat4x4.h"

// Implementation of mat4x4f::mat4x4f() from mat4x4.h
mat4x4f::mat4x4f() {};

// Implementation of mat4x4f::identity() from mat4x4.h
void mat4x4f::identity()
{
	data[0][0] = 1;
	data[1][1] = 1;
	data[2][2] = 1;
	data[3][3] = 1;
}

// Implementation of mat4x4f::perspective() from mat4x4.h
void mat4x4f::perspective(const float fov, const float nearClip, const float farClip)
{
	float scale = (float)(1 / tan(fov * 0.5 / std::numbers::pi / 180));
	data[0][0] = scale;
	data[1][1] = scale;
	data[2][2] = -farClip / (farClip - nearClip);  // Used to remap Z to [0,1] 
	data[3][2] = -farClip * nearClip / (farClip - nearClip); // Used to remap Z to [0,1]
	data[2][3] = -1; // Set W to -Z
	data[3][3] = 0;
}

// Implementation of mat4x4f::translate() from mat4x4.h
void mat4x4f::translate(vec3 offset)
{
	// First initilize the matrix as an identity matrix
	identity();
	
	// Then add in the translation offset
	data[0][3] = offset.data[0];
	data[1][3] = offset.data[1];
	data[2][3] = offset.data[2];
}

mat4x4f::operator std::string() const {
	std::stringstream resultString;
	resultString <<
		"{" << "{" << data[0][0] << ", " << data[0][1] << ", " << data[0][2] << ", " << data[0][3] << "},\n" <<
			  " {" << data[1][0] << ", " << data[1][1] << ", " << data[1][2] << ", " << data[1][3] << "},\n" <<
			  " {" << data[2][0] << ", " << data[2][1] << ", " << data[2][2] << ", " << data[2][3] << "},\n" <<
			  " {" << data[3][0] << ", " << data[3][1] << ", " << data[3][2] << ", " << data[3][3] << "}}\n";

	return resultString.str();
}


// Implementation of mat4x4i::mat4x4i() from mat4x4.h
mat4x4i::mat4x4i() {};

// Implementation of mat4x4i::identity() from mat4x4.h
void mat4x4i::identity()
{
	data[0][0] = 1;
	data[1][1] = 1;
	data[2][2] = 1;
	data[3][3] = 1;
}