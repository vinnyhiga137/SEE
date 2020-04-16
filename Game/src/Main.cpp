// Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "framework.h"
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main() {
    foo();

	if (!glfwInit())
	{
		// Handle initialization failure
		std::cout << "[FATAL] OpenGL can't be initialized!" << std::endl;
	}
}
