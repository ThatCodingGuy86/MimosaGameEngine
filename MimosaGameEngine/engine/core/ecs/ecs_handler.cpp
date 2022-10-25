#include "ecs_handler.h"

uint32_t ecs::RegisterComponent(Component comp)
{
	registeredComponents.push_back(comp);
	return registeredComponents.size() - 1;
}

void ecs::RegisterSystem(ecs::System sys) { registeredSystems.push_back(sys); }

// Creates an empty entity and returns its ID
uint32_t ecs::CreateEntity()
{
	entities.push_back(Entity(entities.size()));
	return entities.size() - 1;
}

// Returns a pointer to the entity with the ID `id`
ecs::Entity* ecs::GetEntityFromID(uint32_t id)
{
	return &entities[id];
}

/*
   Attaches a registered component to the given Entity,
   and returns a pointer to the attached Component
*/
ecs::Component* ecs::AttachComponent(uint32_t entityID, uint32_t compID)
{
	entities[entityID].components.push_back(registeredComponents[compID]);
	return &entities[entityID].components[entities[entityID].components.size() - 1];
}