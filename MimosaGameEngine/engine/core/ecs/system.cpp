#include "system.h"

// Reference: Entity Component System/Systems

ecs::System::System()
{
	isMimSL = false;
}

/* Register a new Callback for this System.
   `args` specifies the names of the types.
   (from `std::type_info::name`)
*/
void ecs::System::RegisterCallback(std::string name, std::vector<std::string> args)
{
	




	//callbacks.push_back(callback);
}

/* Call the Callback with name
   `name`. Will return the Callback's
   return value/type.
*/
std::any ecs::System::CallCallback(std::string name, std::vector<std::any> args)
{
	for (auto& callback : callbacks)
	{
		if (callback.GetName() == name)
		{
			return callback.Call(args);
		}
	}
}