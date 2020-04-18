// framework.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "Application.h"
#include "Core.h"
#include <iostream>
#include <GLFW/glfw3.h>


void Application::init() {

	std::cout << "Hello Game World!" << std::endl;

	if (!glfwInit())
	{
		// Handle initialization failure
		std::cout << "[FATAL] OpenGL can't be initialized!" << std::endl;
	}
    else {

		SEE::Core::start();
        
    }



}