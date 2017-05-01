#include "LedBlinkTask.h"
#include "Task.h"
#include <Keypad\Keypad.h>

byte keys[2][3]{
	{ 1, 3, 5 },
	{ 2, 4, 6 }
};

byte rowPins[2] = { 6, 7 };
byte colPins[3] = { 3, 4, 5 };

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, 2, 3);

Task* tasks[2];

void setup()
{
	tasks[0] = new LedBlinkTask();
	tasks[0]->init(50, 12);
	tasks[1] = new LedBlinkTask();
	tasks[1]->init(1000, 13);

	Serial.begin(9600);
}

void loop()
{
	updateTasks();
	updateKeys();
}

void updateTasks()
{
	for (byte i = 0; i < 2; ++i)
	{
		tasks[i]->update();
	}
}

void updateKeys() 
{
	if (keypad.getKeys()) 
	{
		for (int i = 0; i < LIST_MAX; ++i)
		{
			if (keypad.key[i].stateChanged) 
			{
				interpretInteraction(keypad.key[i].kchar - 1, keypad.key[i].kstate);
			}
		}
	}
}

void interpretInteraction(char command, KeyState state) 
{
	if (command > 2) {
		return;
	}

	switch (state)
	{
	case PRESSED:
		if (command % 2 == 0) 
		{
			tasks[command + 1]->lock();
		}
		else 
		{
			tasks[command - 1]->lock();
		}
		tasks[command]->start();
		break;
	case HOLD:
		break;
	case RELEASED:
		break;
	case IDLE:
		tasks[command]->stop();
		if (command % 2 == 0)
		{
			tasks[command + 1]->unlock();
		}
		else
		{
			tasks[command - 1]->unlock();
		}
		break;
	default:
		break;
	}
}