#pragma once

#include <Windows.h>

class message_pump
{
protected:
	MSG _msg;
public:
	message_pump();
	~message_pump();
	int pump();
	int pump_once();
};

