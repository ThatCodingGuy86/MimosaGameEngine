#include "any_equal.h"
#include <iostream>

// Strict equality. LHS and RHS must be matching types and data.
bool any_strict_equal(std::any lhs, std::any rhs)
{
	if (lhs.type() != rhs.type())
		return false;

	//std::cout << lhs.type().name() << " " << rhs.type().name() << "\n";

	/*
	   This is probably not portable, but I honestly don't see a way I
	   could get the underlying data from std::any with no type information otherwise.
	*/

	void* lhsPtr = &lhs;
	void* rhsPtr = &rhs;

	uint8_t* lhsData = reinterpret_cast<uint8_t*>(lhsPtr);
	uint8_t* rhsData = reinterpret_cast<uint8_t*>(rhsPtr);

	// This probably doesn't work.
	return *lhsData == *rhsData;
}

// Type equality. LHS and RHS must be matching types.
bool any_type_equal(std::any lhs, std::any rhs) { return lhs.type() == rhs.type(); }