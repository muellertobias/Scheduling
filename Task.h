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
	 bool isRunning;

	 bool isExecutionTime();
	 void onAfterExecution();

 public:
	 Task();

	 void init(uint16_t pin, uint16_t delay);
	 virtual void update() = 0;
	 virtual void stop();
	 virtual void start();
};

//extern TaskClass Task;

#endif

