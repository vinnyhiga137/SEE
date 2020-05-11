#pragma once
#include "pch.h"

namespace SEE {
	class Core {
	private:

		// Local attributes
		static SEE::Core* instance;
		GLFWwindow* window;

		Core();
		~Core();

		/// Main loop for the application.
		/// All the game engine logic goes here and will be executed any subsystem 
		/// per frame per second.
		void tick();

	public:

		/// Starts the main loop of the application.
		static void start(GLFWwindow* window);

		/// Stops the main loop of the application.
		static void stop();

	};
}
