#pragma once
#include "event.h"

namespace evnt
{
	std::vector<Event> eventQueue;

	void TriggerEvent(Event event)
	{
		if (eventQueue.size() == 16)
		{
			logger->warn("Event queue size equals 16, lower priority Events will be dropped!\n");

			// Always remove the lowest priority Event

			int lowestPriority = MAXINT32;
			int lowestPriorityIndex = -1;
			for (int i = 0; i < eventQueue.size(); i++)
			{
				Event e = eventQueue[i];

				if (e.priority <= lowestPriority)
				{
					lowestPriority == e.priority;
					lowestPriorityIndex = i;
				}
			}

			if (event.priority >= lowestPriority)
				eventQueue[lowestPriorityIndex] = event;

			if (event.priority < lowestPriority)
				logger->warn("Event dropped, priority is lower than the ones already in queue\n");

			return;
		}

		eventQueue.push_back(event);
	}

	void HandleEvents()
	{

	}
}
