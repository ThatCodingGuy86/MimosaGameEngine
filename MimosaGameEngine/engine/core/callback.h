#pragma once
#include <string>
#include <any>
#include <vector>
#include <functional>
#include "globals.h"

class Callback
{
private:
	// The name of the callback
	std::string name;

	// MSL VM signature, only used for MimSL callbacks
	std::string signature;

	/*
	   std::function for the native callback
	   (First arg is always the name of the callback)
	*/
	std::function<std::any(std::vector<std::any>)> func;

	// Is this callback into a MimSL script
	bool isMSL;

public:
	/*
	   Constructor for native callbacks
	   (First arg is always the name of the callback)
	*/
	Callback(std::string _name, std::function<std::any(std::vector<std::any>)> _func);

	// Constructor for MimSL callbacks
	Callback(std::string _name, std::string _signature);

	// Get the Callback's name
	std::string GetName();

	// Call the function linked to this callback
	std::any Call(std::vector<std::any> args);
};