#include "abstract_window.h"

namespace win32lib
{
	abstract_window::abstract_window()
	{
		_hinstance = GetModuleHandle(NULL);
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
			_parent->get_hwnd(),
			_hmenu,
			_hinstance,
			this                    // pointer to this class instance
			);

		if (!_hwnd) return false;
		else return true;

	}
}