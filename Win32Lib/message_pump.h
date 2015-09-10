#pragma once

#include <Windows.h>
namespace win32lib
{
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
}
