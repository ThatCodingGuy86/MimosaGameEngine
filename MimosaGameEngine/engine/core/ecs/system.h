#pragma once
#include <vector>
#include <tuple>
#include "../callback.h"

// Reference: Entity Component System/Systems

namespace ecs
{
	class System
	{
	public:
		/*
		   The required components for this
		   System to act upon an Entity
		*/
		std::vector<std::string> requiredComponents;

		/*
		   The Callbacks for this System.
		   The first 3 are always initilized
		   for MimSL Systems, as they
		   correspond to the 3 functions
		   Init, Update, and PhysUpdate
		   in MimSL scripts.
		*/
		std::vector<Callback> callbacks;
		
		// Is this a MimSL System
		bool isMimSL;

		// Native Constructor
		System();

		// MimSL Constructor
		// TODO: Add MimSL Constructor

		// Register a new MimSL Callback for this System.
		void RegisterCallback(std::string name, std::string signature);

		/*
		   Register a std::vector of all native Callbacks
		   *MUST ONLY BE CALLED ONCE, AT INITIALIZATION*
		*/
		void RegisterNativeCallbacks(std::vector<std::tuple<std::string /* NAME */, std::function<std::any(std::vector<std::any>)> /* FUNC */>> v);

		/*
		   Call the Callback with name
		   `name`. Will return the Callback's
		   return value/type.
		*/
		std::any CallCallback(std::string name, std::vector<std::any> args);
	};
}
