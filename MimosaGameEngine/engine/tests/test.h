#pragma once
#include <vector>
#include <functional>
#include <map>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <thread>
#include <chrono>
#include "../core/datatypes/vec3.h"
#include "../rendering/datatypes/mat4x4.h"
#include "../core/log.h"
#include "../core/globals.h"
#include "assert.h"

namespace tests
{
	static std::vector<std::function<void(void)>> tests;

	void initTests();

	bool runTests();

	int testMain();
}