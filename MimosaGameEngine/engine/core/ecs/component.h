#pragma once
#include <vector>
#include <any>

// Reference: Entity Component System/Components

namespace ecs
{
	class Component
	{
	public:
		uint32_t id;

		std::vector<std::any> data;
	};
}
