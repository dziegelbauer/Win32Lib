#pragma once

#include <Windows.h>

namespace win32lib
{
	enum window_styles : DWORD
	{
		overlapped = WS_OVERLAPPED,
		popup =  WS_POPUP,
		child = WS_CHILD,
		minimize = WS_MINIMIZE,
		visible = WS_VISIBLE,
		disabled = WS_DISABLED,
		clipsiblings = WS_CLIPSIBLINGS,
		clipchildren = WS_CLIPCHILDREN,
		maximize = WS_MAXIMIZE,
		caption = WS_CAPTION,
		border = WS_BORDER,
		dlgframe = WS_DLGFRAME,
		vscroll = WS_VSCROLL,
		hscroll = WS_HSCROLL,
		sysmenu = WS_SYSMENU,
		thickframe = WS_THICKFRAME,
		group = WS_GROUP,
		tabstop = WS_TABSTOP,
		minimizebox = WS_MINIMIZEBOX,
		maximizebox = WS_MAXIMIZEBOX,
		tiled = WS_TILED,
		iconic = WS_ICONIC,
		sizebox = WS_SIZEBOX,
		tiledwindow = WS_TILEDWINDOW,
		overlappedwindow = WS_OVERLAPPEDWINDOW,
		popupwindow = WS_POPUPWINDOW,
		chioldwindow = WS_CHILDWINDOW
	};
}