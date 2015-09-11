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

	enum window_styles_ex : DWORD
	{
		dlgmodalframe = WS_EX_DLGMODALFRAME,
		noparentnotify = WS_EX_NOPARENTNOTIFY,
		topmost = WS_EX_TOPMOST,
		acceptfiles = WS_EX_ACCEPTFILES,
		transparent = WS_EX_TRANSPARENT,
		mdichild = WS_EX_MDICHILD,
		toolwindow = WS_EX_TOOLWINDOW,
		windowedge = WS_EX_WINDOWEDGE,
		clientedge = WS_EX_CLIENTEDGE,
		contexthelp = WS_EX_CONTEXTHELP,
		right = WS_EX_RIGHT,
		left = WS_EX_LEFT,
		rtlreading = WS_EX_RTLREADING,
		ltrreading = WS_EX_LTRREADING,
		leftscrollbar = WS_EX_LEFTSCROLLBAR,
		rightscrollbar = WS_EX_RIGHTSCROLLBAR,
		controlparent = WS_EX_CONTROLPARENT,
		staticedge = WS_EX_STATICEDGE,
		appwindow = WS_EX_APPWINDOW,
		overlappedwindow = WS_EX_OVERLAPPEDWINDOW,
		palettewindow = WS_EX_PALETTEWINDOW,
		layered = WS_EX_LAYERED,
		noinheritlayout = WS_EX_NOINHERITLAYOUT,
		noredirectionbitmap = WS_EX_NOREDIRECTIONBITMAP,
		layoutrtl = WS_EX_LAYOUTRTL,
		composited = WS_EX_COMPOSITED,
		noactivate = WS_EX_NOACTIVATE
	};
}