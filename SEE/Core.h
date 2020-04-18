#pragma once
#include <GLFW/glfw3.h>

namespace SEE {
	class Core {
	private:

		// Local attributes
		static SEE::Core* instance;

		Core();
		~Core();

		/// Main loop for the application.
		/// All the game engine logic goes here and will be executed any subsystem 
		/// per frame per second.
		void tick();

	public:

		/// Starts the main loop of the application.
		static void start();

		/// Stops the main loop of the application.
		static void stop();

	};
}