// framework.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "Application.h"
#include "Core.h"
#include <iostream>

void SEE::Application::init(const char* withName, int withWidth, int withHeight) {

	std::cout << "Initializing the SEE Engine!" << std::endl;

	if (glfwInit() == NULL) {
		// TODO: Handle initialization failure
		// Add dialog box
		std::cout << "[FATAL] OpenGL can't be initialized!" << std::endl;
	}
    else {

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef MAC
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

		// Creating a windowed mode window and its OpenGL context
		GLFWwindow* window = glfwCreateWindow(withWidth, withHeight, withName, NULL, NULL);

		// Checking if the window was created on the desired operating system as a process...
		if (window == NULL) {
			// TODO: Handle error
			glfwTerminate();
		}
		else {

			// Making the window's context as current
			glfwMakeContextCurrent(window);

			// Checking if the context was created successfully
			if (gladLoadGLLoader((GLADloadproc)glfwGetProcAddress) == NULL)
			{
				// TODO: Handle error
				glfwTerminate();
			}
			else {
				SEE::Core::start(window);
			}

		}
        
    }



}
