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
	//toggle = false;
}

bool Task::isExecutionTime()
{
	return lastExecutionTime + delayTime < millis();
}

void Task::onExecution()
{
	lastExecutionTime = millis();
}

//void Task::update()
//{
//	if (lastExecutionTime + delayTime < millis()) 
//	{
//		digitalWrite(ledPin, toggle);
//		toggle = !toggle;
//		lastExecutionTime = millis();
//	}
//}

//TaskClass Task;
