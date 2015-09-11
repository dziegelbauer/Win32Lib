#pragma once

#include <Windows.h>
#include <string>
#include <memory>
#include "abstract_window.h"
#include "brush.h"

namespace win32lib
{
	class window_class_ex : protected WNDCLASSEX
	{
	public:
		window_class_ex(const std::string* className, brush* window_brush = NULL);
		~window_class_ex();

		// registers the class
		virtual bool Register();

		//retrieve the class name
		virtual const std::string* className() const { return new std::string(lpszClassName); }
	};
}
