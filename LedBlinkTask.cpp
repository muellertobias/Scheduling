// 
// 
// 

#include "LedBlinkTask.h"

void LedBlinkTask::start()
{
	Task::start();
}

void LedBlinkTask::stop()
{
	digitalWrite(ledPin, false);
	Task::stop();
}

LedBlinkTask::LedBlinkTask()
{
	toggle = true;
}

void LedBlinkTask::update()
{
	if (isExecutionTime()) {
		digitalWrite(ledPin, toggle);
		toggle = !toggle;
		onAfterExecution();
	}
}
