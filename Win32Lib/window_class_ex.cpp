#include "window_class_ex.h"
#include "brush.h"

namespace win32lib
{
	window_class_ex::window_class_ex(HINSTANCE hInst, const std::string* className)
	{
		hInstance = hInst;
		// all messages for windows belonging to this Window Class will get sent to msgRouter
		lpfnWndProc = abstract_window::msgRouter;
		char* buffer = new char[className->length + 1];
		className->copy(buffer, className->length, 0);
		buffer[className->length] = '\0';
		lpszClassName = buffer;

		lpszMenuName = 0;
		cbSize = sizeof (WNDCLASSEX);
		cbClsExtra = 0;
		cbWndExtra = 0;
		style = 0;
		hIcon = ::LoadIcon(NULL, IDI_APPLICATION);
		hIconSm = ::LoadIcon(NULL, IDI_APPLICATION);
		hCursor = ::LoadCursor(NULL, IDC_ARROW);
		hbrBackground = (HBRUSH) ::GetStockObject(COLOR_BTNFACE);
	}

	window_class_ex::window_class_ex(const std::string* className)
	{
		hInstance = GetModuleHandle(NULL);
		// all messages for windows belonging to this Window Class will get sent to msgRouter
		lpfnWndProc = abstract_window::msgRouter;
		char* buffer = new char[className->length + 1];
		className->copy(buffer, className->length, 0);
		buffer[className->length] = '\0';
		lpszClassName = buffer;

		lpszMenuName = 0;
		cbSize = sizeof (WNDCLASSEX);
		cbClsExtra = 0;
		cbWndExtra = 0;
		style = 0;
		hIcon = ::LoadIcon(NULL, IDI_APPLICATION);
		hIconSm = ::LoadIcon(NULL, IDI_APPLICATION);
		hCursor = ::LoadCursor(NULL, IDC_ARROW);
		hbrBackground = (HBRUSH) ::GetStockObject(COLOR_BTNFACE);
	}

	window_class_ex::~window_class_ex()
	{
	}

	bool window_class_ex::Register()
	{
		if (::RegisterClassEx(this)) // we pass the this pointer because our class inherits from WNDCLASSEX
			return true;
		else
			return false;
	}
}