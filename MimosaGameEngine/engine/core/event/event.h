#pragma once
#include <string>
#include <vector>
#include "../ecs/ecs_handler.h"

namespace evnt
{
	class Event
	{
	public:
		std::vector<std::string> callbacksToCall;
		std::vector<std::vector<std::any>> callbackArgs;
		ecs::System* system;

		int priority;

		// Call the Callbacks associated with this Event
		void CallCallbacks();
	};
}