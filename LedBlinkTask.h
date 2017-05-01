// LedBlinkTask.h

#ifndef _LEDBLINKTASK_h
#define _LEDBLINKTASK_h

#include "Task.h"

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class LedBlinkTask : public Task
{
private:


protected:
	 bool toggle;
	 virtual void start();
	 virtual void stop();

public:
	LedBlinkTask();

	 void update();
};


#endif

