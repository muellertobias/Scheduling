// Task.h

#ifndef _TASK_h
#define _TASK_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class Task
{
 protected:
	 byte ledPin;
	 uint16_t delayTime;
	 unsigned long lastExecutionTime;

	 bool isExecutionTime();
	 void onExecution();

 public:
	 Task();

	 void init(uint16_t pin, uint16_t delay);
	 virtual void update() = 0;
};

//extern TaskClass Task;

#endif

