#pragma once
#include <any>
#include <string>

// Strict equality. LHS and RHS must be matching types and data.
bool any_strict_equal(std::any lhs, std::any rhs);

// Type equality. LHS and RHS must be matching types.
bool any_type_equal(std::any lhs, std::any rhs);