#pragma once
#include <vector>
#include <any>
#include <string>
#include "../globals.h"

// Reference: Entity Component System/Components

namespace ecs
{
	class Component
	{
	private:
		uint32_t id = -1;
	public:
		std::vector<std::any> data;
		std::string name;

		Component(std::string _name);

		uint32_t GetID();

		/*
		   Can only be called once. Do not call this while
		   creating the Component, this is intended to be
		   called by the ECS handler.
		*/
		void InitID(uint32_t _id);
	};
}
