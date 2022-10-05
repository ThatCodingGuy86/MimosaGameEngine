#include "entity.h"

// Reference: Entity Component System/Entities

// Initialize the Entity with the given ID (MUST BE UNIQUE)
ecs::Entity::Entity(uint32_t _id) { id = _id; }

// Get the ID of this Entity
uint32_t ecs::Entity::GetID() { return id; }