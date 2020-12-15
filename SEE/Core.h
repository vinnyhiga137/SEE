#pragma once
#include "pch.h"

namespace SEE {
	class Core {
	private:

		// Local attributes
		static SEE::Core* instance;
		GLFWwindow* window;

		SEE::Render* render;


		Core();
		~Core();

		/// Main loop for the application.
		/// All the game engine logic goes here and will be executed any subsystem 
		/// per frame per second.
		void tick();

	public:

		/// Starts the main loop of the application.
		/// Parameters:
		/// - window: The instance of a opengl rendered window to be used within.
		static void start(GLFWwindow* window);

		/// Stops the main loop of the application.
		/// WARNING: This also stops the opengl context and respective opengl rendered window!
		static void stop();

	};
}
