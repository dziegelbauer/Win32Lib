#pragma once

#include <Windows.h>
namespace win32lib
{
	class brush
	{
	public:
		brush();
		~brush();
		const HBRUSH get_handle() { return _hbrush }
	protected:
		HBRUSH _hbrush;
	};
}
