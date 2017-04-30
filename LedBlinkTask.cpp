// 
// 
// 

#include "LedBlinkTask.h"

LedBlinkTask::LedBlinkTask()
{
	toggle = false;
}

void LedBlinkTask::update()
{
	if (isExecutionTime()) {
		digitalWrite(ledPin, toggle);
		toggle = !toggle;
		onExecution();
	}
}
