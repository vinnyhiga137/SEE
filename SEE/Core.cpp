#include "Core.h"

SEE::Core* SEE::Core::instance = nullptr;


SEE::Core::Core() {

    // Initializing local attributes
    SEE::Core::window = nullptr;

}



SEE::Core::~Core() {
    // Must delete all references to avoid memory leak
}



/// Main loop for the application.
/// All the game engine logic goes here and will be executed any subsystem 
/// per frame per second.
void SEE::Core::tick() {

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window))
    {
        // Render here
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }
    

}



/// Starts the main loop of the application.
void SEE::Core::start(GLFWwindow* window) {

	if (SEE::Core::instance == nullptr) {
		SEE::Core::instance = new SEE::Core();
        SEE::Core::instance->window = window;

        SEE::Core::instance->tick();
	}

}



/// Stops the main loop of the application.
void SEE::Core::stop() {

    if (SEE::Core::instance != nullptr) {
        glfwTerminate();
        SEE::Core::instance->window = nullptr;
        delete SEE::Core::instance;
    }

}