#include "message_pump.h"

namespace win32lib
{
	message_pump::message_pump()
	{
	}


	message_pump::~message_pump()
	{
	}

	int message_pump::pump()
	{
		int status;
		while ((status = ::GetMessage(&_msg, 0, 0, 0)) != 0)
		{
			if (status == -1) {
				// handle the error, break
				break;
			}
			::TranslateMessage(&_msg);
			::DispatchMessage(&_msg);
		}
		return _msg.wParam;
	}

	int message_pump::pump_once()
	{
		int status = ::GetMessage(&_msg, 0, 0, 0);

		if (status)
		{
			::TranslateMessage(&_msg);
			::DispatchMessage(&_msg);
		}
		return status;
	}
}