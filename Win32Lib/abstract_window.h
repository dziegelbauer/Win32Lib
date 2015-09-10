#pragma once
#pragma once

#include <Windows.h>
#include <string>
#include <memory>

class abstract_window
{
public:
	abstract_window();
	abstract_window(HINSTANCE);
	~abstract_window();
	static LRESULT CALLBACK msgRouter(HWND, UINT, WPARAM, LPARAM);
	virtual LRESULT CALLBACK wndProc(HWND, UINT, WPARAM, LPARAM) = 0;
	bool Create();
	int Show();
	HWND get_hwnd() { return _hwnd };
protected:
	HWND _hwnd;
	abstract_window* _parent;
	RECT _window_rect;
	DWORD _style;
	DWORD _style_ex;
};

