#include "LedBlinkTask.h"
#include "Task.h"

Task* tasks[2];

void setup()
{
	tasks[0] = new LedBlinkTask();
	tasks[0]->init(12, 250);
	tasks[1] = new LedBlinkTask();
	tasks[1]->init(13, 1000);
}

void loop()
{
	for (byte i = 0; i < 2; ++i) 
	{
		tasks[i]->update();
	}
}

