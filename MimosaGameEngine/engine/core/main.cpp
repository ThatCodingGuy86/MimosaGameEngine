#include <iostream>
#include <vector>
#include <string>
#include <any>
#include "globals.h"
#include "../tests/test.h"
#include "ecs/system.h"

int main(int argc, char* argv[])
{
	logger = new Logger(true);

	std::vector<std::string> argv_s;

	// Copy argv to a std::vector<std::string> for ease of use
	for (int i = 0; i < argc; i++)
		argv_s.push_back(argv[i]);

	if (argv_s.size() >= 2 && argv_s[1] == "--test")
		return tests::testMain();

	logger->log("Starting Mimosa Game Engine...\n");

	std::vector<std::tuple<std::string /* NAME */, std::function<std::any(std::vector<std::any>)> /* FUNC */>> callbacks;
	
	std::function<std::any(std::vector<std::any>)> func = [](std::vector<std::any> args) {
		try
		{
			if (std::any_cast<int>(args[1]) == 1)
			{
				std::any helloWorld = (std::string)"Hello World!\n";
				return helloWorld;
			}
				
		}
		catch(const std::bad_any_cast& e)
		{
			std::cout << e.what() << " in " << std::any_cast<std::string>(args[0]) << "\n";

			std::any nothing;
			return nothing;

		}
	};


	callbacks.push_back(std::make_tuple("test", func));
	
	ecs::System system = ecs::System();
	system.RegisterNativeCallbacks(callbacks);

	std::vector<std::any> args;
	std::any arg = 1;
	args.push_back(arg);

	std::cout << logger->serialize(system.CallCallback("test", args));

	args.clear();

	arg = "Not Valid";
	args.push_back(arg);
	
	std::cout << logger->serialize(system.CallCallback("test", args));
}