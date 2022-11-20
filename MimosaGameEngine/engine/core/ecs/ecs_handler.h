#pragma once
#include <vector>
#include "../helper/any_equal.h"
#include "entity.h"
#include "component.h"
#include "system.h"
#include "../globals.h"

namespace ecs
{
	static std::vector<Component> registeredComponents;
	static std::vector<System> registeredSystems;

	static std::vector<Entity> entities;

	uint32_t RegisterComponent(Component comp);

	void RegisterSystem(System sys);

	// Creates an empty entity and returns its ID.
	uint32_t CreateEntity();

	// Returns a pointer to the entity with the ID `id`.
	Entity* GetEntityFromID(uint32_t id);

	/*
	   Returns a pointer to an entity with a Component
	   that has data entry `entry` and name `compName`.
	*/
	Entity* GetEntityFromCompData(std::string compName, std::any entry);

	/*
	   Returns a pointer to an entity with a Transform
	   Component with name field `name`.
	*/
	Entity* GetEntityFromTransfName(std::string name);

	/*
	   Returns a list of pointers to all Entities with
	   a Transform Component with tag field `tag`.
	*/
	std::vector<Entity*> GetEntitiesWithTag(std::string tag);

	/*
	   Attaches a registered component to the given Entity,
	   and returns a pointer to the attached Component.
	*/
	Component* AttachComponent(uint32_t entityID, uint32_t compID);

	/*
	   Attaches a registered component to the given Entity,
	   and returns a pointer to the attached Component.
	*/
	Component* AttachComponent(uint32_t entityID, std::string compName);
}