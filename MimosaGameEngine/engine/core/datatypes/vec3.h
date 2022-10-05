#pragma once
#include <string>
#include "../log.h"
#include "../globals.h"

/*
Predefine class so no circular dependency is
required between vec3.h and mat4x4.h
*/

class mat4x4f;

class vec3
{
public:
	// The components of the vector
	float data[3];

	// Default constructor, initilizes the components to 0
	vec3();

	// Initilizes the components to x, y, & z
	vec3(float x, float y, float z);

	// Integer version of the float constructor
	vec3(int x, int y, int z);


	vec3& operator+=(const vec3& rhs);

	vec3& operator+=(const float rhs);

	vec3& operator-=(const vec3& rhs);

	vec3& operator-=(const float rhs);

	vec3& operator*=(const vec3& rhs);

	vec3& operator*=(const float rhs);

	vec3& operator*=(const mat4x4f rhs);

	vec3& operator/=(const vec3& rhs);

	vec3& operator/=(const float rhs);


	friend vec3& operator+(vec3& lhs, const vec3& rhs);

	friend vec3& operator+(vec3& lhs, const float rhs);

	friend vec3& operator-(vec3& lhs, const vec3& rhs);

	friend vec3& operator-(vec3& lhs, const float rhs);

	friend vec3& operator*(vec3& lhs, const vec3& rhs);

	friend vec3& operator*(vec3& lhs, const float rhs);

	friend vec3& operator*(vec3& lhs, const mat4x4f rhs);

	friend vec3& operator/(vec3& lhs, const vec3& rhs);

	friend vec3& operator/(vec3& lhs, const float rhs);


	bool operator==(const vec3& rhs);
	bool operator!=(const vec3& rhs);


	operator std::string() const;
};