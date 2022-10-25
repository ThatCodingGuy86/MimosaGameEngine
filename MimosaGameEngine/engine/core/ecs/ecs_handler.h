#pragma once
#include <vector>
#include "entity.h"
#include "component.h"
#include "system.h"

namespace ecs
{
	std::vector<Component> registeredComponents;
	std::vector<System> registeredSystems;

	std::vector<Entity> entities;

	uint32_t RegisterComponent(Component comp);

	void RegisterSystem(System sys);

	// Creates an empty entity and returns its ID
	uint32_t CreateEntity();

	// Returns a pointer to the entity with the ID `id`
	Entity* GetEntityFromID(uint32_t id);

	/*
	   Attaches a registered component to the given Entity,
	   and returns a pointer to the attached Component
	*/
	Component* AttachComponent(uint32_t entityID, uint32_t compID);
}