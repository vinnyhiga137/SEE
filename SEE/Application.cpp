// framework.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "Application.h"
#include "Core.h"
#include <iostream>

void SEE::Application::init() {

	std::cout << "Hello Game World!" << std::endl;

	if (!glfwInit()) {
		// Handle initialization failure
		std::cout << "[FATAL] OpenGL can't be initialized!" << std::endl;
	}
    else {

		// Creating a windowed mode window and its OpenGL context
		GLFWwindow* window = glfwCreateWindow(1280, 720, "Game Application", NULL, NULL);

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
