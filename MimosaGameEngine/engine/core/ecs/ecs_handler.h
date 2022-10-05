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

	void RegisterComponent(Component comp);

	void RegisterSystem(System sys);


}