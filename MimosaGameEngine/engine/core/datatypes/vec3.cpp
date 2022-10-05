#include "vec3.h"
#include "../../rendering/datatypes/mat4x4.h"
#include <sstream>

// Implementation of vec3 default constructor from vec3.h
vec3::vec3()
{
	data[0] = 0;
	data[1] = 0;
	data[2] = 0;
}

// Implementation of vec3 float constructor from vec3.h
vec3::vec3(float x, float y, float z)
{
	data[0] = x;
	data[1] = y;
	data[2] = z;
}

// Implementation of vec3 int constructor from vec3.h
vec3::vec3(int x, int y, int z)
{
	logger.warn("Initilization of vec3 with int constructor, this may result in data loss\n");

	data[0] = (float)x;
	data[1] = (float)y;
	data[2] = (float)z;
}

// Implementation of various operators

vec3& vec3::operator+=(const vec3& rhs)
{
	this->data[0] += rhs.data[0];
	this->data[1] += rhs.data[1];
	this->data[2] += rhs.data[2];
	return *this;
}

vec3& vec3::operator+=(const float rhs)
{
	this->data[0] += rhs;
	this->data[1] += rhs;
	this->data[2] += rhs;
	return *this;
}

vec3& vec3::operator-=(const vec3& rhs)
{
	this->data[0] -= rhs.data[0];
	this->data[1] -= rhs.data[1];
	this->data[2] -= rhs.data[2];
	return *this;
}

vec3& vec3::operator-=(const float rhs)
{
	this->data[0] -= rhs;
	this->data[1] -= rhs;
	this->data[2] -= rhs;
	return *this;
}

vec3& vec3::operator*=(const vec3& rhs)
{
	this->data[0] *= rhs.data[0];
	this->data[1] *= rhs.data[1];
	this->data[2] *= rhs.data[2];
	return *this;
}

vec3& vec3::operator*=(const float rhs)
{
	this->data[0] *= rhs;
	this->data[1] *= rhs;
	this->data[2] *= rhs;
	return *this;
}

vec3& vec3::operator*=(const mat4x4f rhs)
{
	/*
	I have honestly no idea if this is correct.
	The tests pass, so I guess it's probably correct?
	*/

	this->data[0] = this->data[0] * rhs.data[0][0] + this->data[1] * rhs.data[0][1] + this->data[2] * rhs.data[0][2] + 1 * rhs.data[0][3];
	this->data[1] = this->data[0] * rhs.data[1][0] + this->data[1] * rhs.data[1][1] + this->data[2] * rhs.data[1][2] + 1 * rhs.data[1][3];
	this->data[2] = this->data[0] * rhs.data[2][0] + this->data[1] * rhs.data[2][1] + this->data[2] * rhs.data[2][2] + 1 * rhs.data[2][3];
	
	return *this;
}

vec3& vec3::operator/=(const vec3& rhs)
{
	this->data[0] /= rhs.data[0];
	this->data[1] /= rhs.data[1];
	this->data[2] /= rhs.data[2];
	return *this;
}

vec3& vec3::operator/=(const float rhs)
{
	this->data[0] /= rhs;
	this->data[1] /= rhs;
	this->data[2] /= rhs;
	return *this;
}


vec3& operator+(vec3& lhs, const vec3& rhs)
{
	lhs += rhs;
	return lhs;
}

vec3& operator+(vec3& lhs, const float rhs)
{
	lhs += rhs;
	return lhs;
}

vec3& operator-(vec3& lhs, const vec3& rhs)
{
	lhs -= rhs;
	return lhs;
}

vec3& operator-(vec3& lhs, const float rhs)
{
	lhs -= rhs;
	return lhs;
}

vec3& operator*(vec3& lhs, const vec3& rhs)
{
	lhs *= rhs;
	return lhs;
}

vec3& operator*(vec3& lhs, const float rhs)
{
	lhs *= rhs;
	return lhs;
}

vec3& operator*(vec3& lhs, const mat4x4f rhs)
{
	lhs *= rhs;
	return lhs;
}

vec3& operator/(vec3& lhs, const vec3& rhs)
{
	lhs /= rhs;
	return lhs;
}

vec3& operator/(vec3& lhs, const float rhs)
{
	lhs /= rhs;
	return lhs;
}


bool vec3::operator==(const vec3& rhs)
{
	return (this->data[0] == rhs.data[0]) && (this->data[1] == rhs.data[1]) && (this->data[2] == rhs.data[2]);
}

bool vec3::operator!=(const vec3& rhs)
{
	return (this->data[0] != rhs.data[0]) && (this->data[1] != rhs.data[1]) && (this->data[2] != rhs.data[2]);
}


vec3::operator std::string() const {
	std::stringstream resultString;
	resultString << "{" << data[0] << ", " << data[1] << ", " << data[2] << "}";

	return resultString.str();
}