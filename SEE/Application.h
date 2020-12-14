#pragma once
#include "pch.h"

namespace SEE {
	class Application {
	public:

		/// Creates the main window for the application.
		/// Parameters:
		/// - withName: The name for the window.
		/// - withWidth: The width of the window.
		/// - withHeight: The height of the window.
		static void init(const char* withName, int withWidth, int withHeight);
	};
}