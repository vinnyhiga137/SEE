#include "Core.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

SEE::Core* SEE::Core::instance = nullptr;


SEE::Core::Core() {

    // Initializing local attributes
    SEE::Core::window = nullptr;
    SEE::Core::render = nullptr;

}



SEE::Core::~Core() {
    // Must delete all references to avoid memory leak
}



/// Main loop for the application.
/// All the game engine logic goes here and will be executed any subsystem 
/// per frame per second.
void SEE::Core::tick() {

    std::vector<float> vertices;

    vertices.push_back(-0.5f);
    vertices.push_back(-0.5f);
    vertices.push_back(0.0f);

    vertices.push_back(0.0f);
    vertices.push_back(0.5f);
    vertices.push_back(0.0f);

    vertices.push_back(0.0f);
    vertices.push_back(-0.5f);
    vertices.push_back(0.0f);

    SEE::Sprite* sprite = new SEE::Sprite(&vertices);


    this->render->SetupShaderProgram("testVertex.vsh", "testFragment2.fsh", sprite);

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(this->window)) {

        // Render here
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        this->render->DrawContent();

        // Swap front and back buffers
        glfwSwapBuffers(this->window);

        // Poll for and process events
        glfwPollEvents();

    }
    

}



/// Starts the main loop of the application.
void SEE::Core::start(GLFWwindow* window) {

	if (SEE::Core::instance == nullptr) {
		SEE::Core::instance = new SEE::Core();
        SEE::Core::instance->window = window;

        // Initializing the subsystems
        SEE::Core::instance->render = SEE::Render::Render::GetInstance();

        // Running the main game loop
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