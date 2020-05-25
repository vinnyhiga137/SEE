// framework.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "Application.h"
#include "Core.h"
#include <iostream>

void SEE::Application::init(const char* name) {

	std::cout << "Hello Game World!" << std::endl;

	if (!glfwInit()) {
		// Handle initialization failure
		std::cout << "[FATAL] OpenGL can't be initialized!" << std::endl;
	}
    else {

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef MAC
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

		// Creating a windowed mode window and its OpenGL context
		GLFWwindow* window = glfwCreateWindow(1280, 720, name, NULL, NULL);

		if (!window) {
			glfwTerminate();
		}
		else {
			// Make the window's context current
			glfwMakeContextCurrent(window);
			SEE::Core::start(window);
		}
        
    }



}
