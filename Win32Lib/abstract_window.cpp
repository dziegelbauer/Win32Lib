#include "abstract_window.h"

namespace win32lib
{
	abstract_window::abstract_window()
	{
		_hinstance = GetModuleHandle(NULL);
		_style_ex = WS_EX_OVERLAPPEDWINDOW;
		_window_text = "";
		_style = WS_OVERLAPPEDWINDOW;
		_window_rect.left = CW_USEDEFAULT;
		_window_rect.top = CW_USEDEFAULT;
		_window_rect.right = CW_USEDEFAULT;
		_window_rect.bottom = CW_USEDEFAULT;
		_parent = NULL;
		_hmenu = NULL;
	}
	
	abstract_window::~abstract_window()
	{
	}

	LRESULT CALLBACK abstract_window::msgRouter(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		abstract_window *wnd = 0;

		if (message == WM_NCCREATE)
		{
			LPCREATESTRUCT cs = reinterpret_cast<LPCREATESTRUCT>(lParam);
			::SetWindowLong(hwnd, GWL_USERDATA, reinterpret_cast<long>(cs->lpCreateParams));
		}
		else
		{
			wnd = reinterpret_cast<abstract_window *>(::GetWindowLong(hwnd, GWL_USERDATA));
		}

		if (wnd)
			wnd->wndProc(hwnd, message, wParam, lParam);
		else
			// for messages that arrive prior to WM_NCCREATE
			// and the HWND <-> AbstractWindow * association was not made
			return ::DefWindowProc(hwnd, message, wParam, lParam);
	}

	bool abstract_window::Create()
	{
		// we'll just assume CreateWindowEx ()'s parameters are protected members of AbstractWindow
		_hwnd = ::CreateWindowEx(
			_style_ex,
			_class_name.c_str(),
			_window_text.c_str(),
			_style,
			_window_rect.left,
			_window_rect.top,
			_window_rect.right,
			_window_rect.bottom,
			_parent ? _parent->get_hwnd() : NULL,
			_hmenu,
			_hinstance,
			this                    // pointer to this class instance
			);

		if (!_hwnd) return false;
		else return true;

	}

	void abstract_window::set_rect(RECT* window_rect)
	{
		memcpy(&_window_rect, &window_rect, sizeof(RECT));
	}
	void abstract_window::set_rect(LONG x, LONG y, LONG width, LONG height)
	{
		_window_rect.left = x;
		_window_rect.top = y;
		_window_rect.right = width;
		_window_rect.left = height;
	}
	void abstract_window::set_style(DWORD style)
	{
		_style = style;
	}
	void abstract_window::set_ex_style(DWORD style)
	{
		_style_ex = style;
	}
}