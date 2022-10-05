#pragma once
#include <vector>
#include "component.h"

// Reference: Entity Component System/Entities

namespace ecs
{
	class Entity
	{
	private:
		uint32_t id = NULL;

	public:
		std::vector<Component> components;

		// Initialize the Entity with the given ID (MUST BE UNIQUE)
		Entity(uint32_t _id);

		// Get the ID of this Entity
		uint32_t GetID();
	};
}
