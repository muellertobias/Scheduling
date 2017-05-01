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

Task* tasks[6];

void setup()
{
	tasks[0] = new LedBlinkTask();
	tasks[0]->init(50, 12);
	tasks[1] = new LedBlinkTask();
	tasks[1]->init(100, 13);
	tasks[2] = new LedBlinkTask();
	tasks[2]->init(500, 11);

	Serial.begin(9600);
}

void loop()
{
	updateTasks();
	updateKeys();
}

void updateTasks()
{
	for (byte i = 0; i < 3; ++i)
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
	if (command > 3) {
		return;
	}

	Serial.println((byte)command);

	switch (state)
	{
	case PRESSED:
		lockTask(command);
		tasks[command]->start();
		break;
	case HOLD:
		break;
	case RELEASED:
		break;
	case IDLE:
		tasks[command]->stop();
		unlockTask(command);
		break;
	default:
		break;
	}
}

void lockTask(char command) 
{
	if (command % 2 == 0)
	{
		if (tasks[command + 1] != NULL)
			tasks[command + 1]->lock();
	}
	else
	{
		if (tasks[command - 1] != NULL)
			tasks[command - 1]->lock();
	}
}

void unlockTask(char command)
{
	if (command % 2 == 0)
	{
		if (tasks[command + 1] != NULL)
			tasks[command + 1]->unlock();
	}
	else
	{
		if (tasks[command - 1] != NULL)
			tasks[command - 1]->unlock();
	}
}