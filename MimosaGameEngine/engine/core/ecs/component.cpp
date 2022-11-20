#include "component.h"

ecs::Component::Component(std::string _name)
{
	name = _name;
}

uint32_t ecs::Component::GetID() { return id; }

void ecs::Component::InitID(uint32_t _id)
{
	if (id == -1) { id = _id; }
	else
	{
		logger->warn("Component " + name + " : " + std::to_string(id) + " Attempted to initilize ID that is already initilized.\n");
	}
}