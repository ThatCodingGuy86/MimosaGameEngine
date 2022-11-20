#include "system.h"

// Reference: Entity Component System/Systems

ecs::System::System()
{
	isMimSL = false;
}

// Register a new MimSL Callback for this System.
void ecs::System::RegisterCallback(std::string name, std::string signature)
{
	/*
	   RegisterCallback can only register MimSL
	   Callbacks, as it is impossible to create
	   `std::function`s with arbitrary code at runtime.
	*/
	Callback callback = Callback(name, signature);
	callbacks.push_back(callback);
}

/*
   Register a std::vector of all native callbacks
   *MUST ONLY BE CALLED ONCE, AT INITIALIZATION*
*/
void ecs::System::RegisterNativeCallbacks(std::vector<std::tuple<std::string /* NAME */, std::function<std::any(std::vector<std::any>)> /* FUNC */>> v)
{
	for (const auto &callback : v)
	{
		auto &[name, func] = callback;
		callbacks.push_back(Callback(name, func));
	}
}

/*
   Call the Callback with name
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