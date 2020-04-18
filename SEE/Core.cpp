#include "Core.h"

SEE::Core* SEE::Core::instance = nullptr;


SEE::Core::Core() {

}



SEE::Core::~Core() {
    // Must delete all references to avoid memory leak
}



/// Main loop for the application.
/// All the game engine logic goes here and will be executed any subsystem 
/// per frame per second.
void SEE::Core::tick() {

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(1280, 720, "Game Application", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
    }
    else {

        // Make the window's context current
        glfwMakeContextCurrent(window);

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

        glfwTerminate();
    }

}



/// Starts the main loop of the application.
void SEE::Core::start() {

	if (SEE::Core::instance == nullptr) {
		SEE::Core::instance = new SEE::Core();

        SEE::Core::instance->tick();
	}

}



/// Stops the main loop of the application.
void SEE::Core::stop() {

    if (SEE::Core::instance != nullptr) {
        delete SEE::Core::instance;
    }

}