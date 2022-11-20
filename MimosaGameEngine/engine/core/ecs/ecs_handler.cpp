#include "ecs_handler.h"

uint32_t ecs::RegisterComponent(Component comp)
{
	registeredComponents.push_back(comp);

	registeredComponents[registeredComponents.size() - 1].InitID(registeredComponents.size() - 1);

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
   Returns a pointer to an entity with a Component
   that has data entry `entry` and name `compName`
*/
ecs::Entity* ecs::GetEntityFromCompData(std::string compName, std::any entry)
{
	uint32_t id = -1;

	for (auto& entity : entities)
	{
		for (auto& comp : entity.components)
		{
			if (comp.name != compName)
				continue;

			for (auto& e : comp.data)
			{
				/*
				   Get rid of obvious non-matches before
				   continuing with a more computationally
				   expensive data equality check
				*/
				if (e.type() != entry.type())
					continue;

				/*
				   I'm questioning why there isn't a equality
				   check in std::any itself, it makes this a
				   lot more annoying
				*/

				if (any_strict_equal(e, entry))
					id = entity.GetID();
			}
		}
	}

	if (id == -1)
	{
		logger->warn("Could not find an entity with component " + compName + " and data " + logger->serialize(entry) + "\n");
		return nullptr;
	}

	return &entities[id];
}

/*
   Returns a pointer to an entity with a Transform
   Component with name field `name`.
*/
ecs::Entity* ecs::GetEntityFromTransfName(std::string name)
{
	uint32_t id = -1;

	for (auto& entity : entities)
	{
		for (auto& component : entity.components)
		{
			try
			{
				/*
				   The Transform Component should always be registered,
				   so no need to check if the ID is registered
				*/
				if (component.name == "Transform" && std::any_cast<std::string>(component.data[0]) == name)
				{
					return &entity;
				}
			}
			catch (std::bad_any_cast& e)
			{
				logger->err("Bad any_cast in GetEntityFromTransfName, the Transform component is corrupted!\n");
				return nullptr;
			}
		}
	}

	logger->warn("No Entity found with name " + name + ". Check if the name is spelled and capitilized correctly.\n");
	return nullptr;
}

/*
   Returns a list of pointers to all Entities with
   a Transform Component with tag field `tag`.
*/
std::vector<ecs::Entity*> ecs::GetEntitiesWithTag(std::string tag)
{
	std::vector<ecs::Entity*> entityList;
	for (auto& entity : entities)
	{
		for (auto& component : entity.components)
		{
			if (component.name == "Transform" && std::any_cast<std::string>(component.data[1]) == tag)
			{
				entityList.push_back(&entity);
			}
		}
	}
	return entityList;
}

/*
   Attaches a registered component to the given Entity,
   and returns a pointer to the attached Component.
   (Warning, pointer is invalid when the entities std::vector
    reallocates)
*/
ecs::Component* ecs::AttachComponent(uint32_t entityID, uint32_t compID)
{
	// This is a verbose mess. Hopefully nobody else has to touch this.

	entities[entityID].components.push_back(registeredComponents[compID]);
	return &entities[entityID].components[entities[entityID].components.size() - 1];
}

/*
   Attaches a registered component to the given Entity,
   and returns a pointer to the attached Component.
   (Warning, pointer is invalid when the entities std::vector
	reallocates)
*/
ecs::Component* ecs::AttachComponent(uint32_t entityID, std::string compName)
{
	uint32_t compID = -1;
	for (auto& comp : registeredComponents)
	{
		if (comp.name == compName)
		{
			compID = comp.GetID();
			break;
		}
	}

	if (compID == -1)
	{
		logger->warn("Could not find component " + compName + "\n");
		return nullptr;
	}

	entities[entityID].components.push_back(registeredComponents[compID]);
	return &entities[entityID].components[entities[entityID].components.size() - 1];
}