#include <iostream>
#include <vector>
#include <string>
#include "globals.h"
#include "../tests/test.h"
#include <any>

int main(int argc, char* argv[])
{
	logger = Logger();

	std::vector<std::string> args;

	// Copy argv to a std::vector<std::string> for ease of use
	for (int i = 0; i < argc; i++)
		args.push_back(argv[i]);

	if (args.size() >= 2 && args[1] == "--test")
		return tests::testMain();

	logger.log("Starting Mimosa Game Engine...");

	std::any a;
	a = true;
	std::cout << a.type().name();
}