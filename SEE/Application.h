#pragma once
#include "pch.h"

namespace SEE {
	class Application {
	public:

		/// Creates the main window for the application.
		/// Parameters:
		/// - name: The name for the window.
		static void init(const char* name);
	};
}