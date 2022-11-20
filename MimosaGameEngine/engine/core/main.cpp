#include <iostream>
#include <vector>
#include <string>
#include <any>
#include "globals.h"
#include "../tests/test.h"
#include "ecs/ecs_handler.h"


int main(int argc, char* argv[])
{
	//return tests::testMain();

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
			else
			{
				std::any nothing;
				return nothing;
			}
		}
		catch(const std::bad_any_cast& e)
		{
			logger->err((std::string)e.what() + " in " + std::any_cast<std::string>(args[0]) + "\n");

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

	logger->log(logger->serialize(system.CallCallback("test", args)));

	args.clear();

	arg = "Not Valid";
	args.push_back(arg);
	
	logger->log(logger->serialize(system.CallCallback("test", args)) + "\n");

	uint32_t entityID = ecs::CreateEntity();

	ecs::Component testComp = ecs::Component("test component");

	uint32_t compID = ecs::RegisterComponent(testComp);

	ecs::Component* comp = ecs::AttachComponent(entityID, "test component");

	std::any entry = 1;
	comp->data.push_back(2);
	comp->data.push_back(3);

	ecs::Entity* entity = ecs::GetEntityFromCompData("test component", entry);

	std::cout << entity->GetID() << " : " << entityID << "\n";

	std::any notEntry = 2;

	ecs::Entity* entity2 = ecs::GetEntityFromCompData("test component", notEntry);

	if (entity2)
	{
		std::cout << entity2->GetID() << " : " << entityID << "\n";
	}
}