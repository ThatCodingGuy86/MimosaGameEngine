#include "event.h"

// Call the Callbacks associated with this Event
void evnt::Event::CallCallbacks()
{
	for (int i = 0; i < callbacksToCall.size(); i++)
	{
		system->CallCallback(callbacksToCall[i], callbackArgs[i]);
	}
}