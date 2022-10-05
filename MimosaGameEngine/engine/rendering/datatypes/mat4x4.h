#pragma once
#include "../../core/datatypes/vec3.h"
#include <numbers>
#include <string>
#include <sstream>

// 4x4 matrix of floats
class mat4x4f
{
public:
	float data[4][4] = {
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}};

	mat4x4f();

	// Set the matrix to an identity matrix
	void identity();

	// Set the matrix to a perspective matrix
	void perspective(const float fov, const float nearClip, const float farClip);

	// Set the matrix to a translation matrix
	void translate(vec3 offset);

	operator std::string() const;
};

// 4x4 matrix of ints
class mat4x4i
{
	int data[4][4] = {
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}};

	mat4x4i();

	// Sets the matrix to an identity matrix
	void identity();
};