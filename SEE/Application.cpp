// framework.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "Application.h"
#include "Core.h"
#include <iostream>

void SEE::Application::init(const char* name) {

	std::cout << "Hello Game World!" << std::endl;

	if (glfwInit() == NULL) {
		// Handle initialization failure
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
		GLFWwindow* window = glfwCreateWindow(1280, 720, name, NULL, NULL);

		// Checking if the window was created on the desired operating system as a process...
		if (window == NULL) {
			glfwTerminate();
		}
		else {

			// Making the window's context as current
			glfwMakeContextCurrent(window);

			// Checking if the context was created successfully
			if (gladLoadGLLoader((GLADloadproc)glfwGetProcAddress) == NULL)
			{
				glfwTerminate();
			}
			else {
				SEE::Core::start(window);
			}

		}
        
    }



}
