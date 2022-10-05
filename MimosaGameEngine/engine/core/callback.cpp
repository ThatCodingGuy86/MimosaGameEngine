#include "callback.h"
#include "globals.h"

// Constructor for native callbacks
Callback::Callback(std::string _name, std::function<std::any(std::vector<std::any>)> _func)
{
	isMSL = false;
	name = _name;
	func = _func;
}

// Constructor for MimSL callbacks
Callback::Callback(std::string _name, std::string _signature)
{
	isMSL = true;
	name = _name;
	signature = _signature;
}

// Get the Callback's name
std::string Callback::GetName() { return name; }

// Call the function linked to this callback
std::any Callback::Call(std::vector<std::any> args)
{
	if (!isMSL)
	{
		// Call native callback
		return func(args);
	}
	else
	{
		// Call MimSL callback

		// TODO: Add implementation of MimSL callbacks

		logger.warn("Attempted to call a MimSL Callback, this is not implemented!");
		return NULL;
	}
}