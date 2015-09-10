#pragma once
#pragma once

#include <Windows.h>
#include <string>
#include <memory>

class abstract_window
{
public:
	abstract_window();
	~abstract_window();
protected:
	HWND m_hwnd;
};

