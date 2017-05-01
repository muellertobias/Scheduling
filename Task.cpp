// 
// 
// 

#include "Task.h"

Task::Task()
{
}

void Task::init(uint16_t pin, uint16_t delay)
{
	ledPin = pin;
	this->delayTime = delay;
	pinMode(ledPin, OUTPUT);
	lastExecutionTime = 0L;
	isRunning = false;
}


void Task::start()
{
	isRunning = true;
}

void Task::stop()
{
	isRunning = false;
}

bool Task::isExecutionTime()
{
	return lastExecutionTime + delayTime < millis() && isRunning;
}

void Task::onAfterExecution()
{
	lastExecutionTime = millis();
}

