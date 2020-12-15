#include "Core.h"
#include <iostream>
#include <fstream>
#include <string>

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


    // TODO: This variables are for testing purpose and should not be
    // in the "master" branch.

    // Aux. variable to loading the vertices position in the 3D Space
    float vertices[] = {
            -0.5f, -0.5f, 0.0f, // Pos 1
            0.0f, 0.5f, 0.0f,   // Pos 2
            0.5f, -0.5f, 0.0f   // Pos 3
    };

    // Generating a buffer where will be setted the values related to a point
    // in 3d space, like it's position & color
    unsigned int testVbo = 0;
    glGenBuffers(1, &testVbo);

    unsigned int testVao = 0;
    glGenVertexArrays(1, &testVao);

    glBindVertexArray(testVao);

    glBindBuffer(GL_ARRAY_BUFFER, testVbo); // Generating ID for that buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // Copying data into that buffer

    // Loading the vertex shader
    SEE::Logger::printInfo("Loading shaders files!");

    char shaderPath[200] = {'\0'};
    std::string vertexSourceLines = "";
    std::string fragmentSourceLines = "";
    std::string fileLine;

    strcpy(shaderPath, GET_SHADER_PATH);
    strcat(shaderPath, "testVertex.vsh");

    std::ifstream reader(shaderPath);

    if (reader.is_open()) {
        while (std::getline(reader, fileLine)) {
            vertexSourceLines.append(fileLine.append("\n"));
        }

        reader.close();
    }
    else {
        SEE::Logger::printFatal("No default vertex shader file was found!");
    }



    // Setting the vertex attributes...
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);



    // Now loading the fragment shader
    strcpy(shaderPath, GET_SHADER_PATH);
    strcat(shaderPath, "testFragment.fsh");

    reader.open(shaderPath);

    if (reader.is_open()) {
        while (std::getline(reader, fileLine)) {
            fragmentSourceLines.append(fileLine.append("\n"));
        }

        reader.close();
    }
    else {
        SEE::Logger::printFatal("No default fragment shader file was found!");
    }



    SEE::Logger::printInfo("Compiling shaders...");


    int wasSuccess = 0;
    char message[500];


    unsigned int testVertexShader;
    testVertexShader = glCreateShader(GL_VERTEX_SHADER);

    const char* vertexSourceCode = vertexSourceLines.c_str();
    glShaderSource(testVertexShader, 1, &vertexSourceCode, NULL);
    glCompileShader(testVertexShader);

    glGetShaderiv(testVertexShader, GL_COMPILE_STATUS, &wasSuccess);

    if (!wasSuccess) {

        char compileMessage[500];

        glGetShaderInfoLog(testVertexShader, 500, NULL, message);

        strcat(compileMessage, "The following error occurred on gpu:\n\n");
        strcat(compileMessage, message);

        SEE::Logger::printError(message);
        SEE::Logger::printFatal("Couldn't compile vertex shader!");
    }


    // TODO: Handle shader compile errors

    unsigned int testFragmentShader;
    testFragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    const char* fragmentSourceCode = fragmentSourceLines.c_str();
    glShaderSource(testFragmentShader, 1, &fragmentSourceCode, NULL);
    glCompileShader(testFragmentShader);


    glGetShaderiv(testFragmentShader, GL_COMPILE_STATUS, &wasSuccess);

    if (!wasSuccess) {

        char compileMessage[500];

        glGetShaderInfoLog(testFragmentShader, 500, NULL, message);

        strcat(compileMessage, "The following error occurred on gpu:\n\n");
        strcat(compileMessage, message);

        SEE::Logger::printError(message);
        SEE::Logger::printFatal("Couldn't compile vertex shader!");
    }


    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();



    SEE::Logger::printInfo("Linking shader program!");


    glAttachShader(shaderProgram, testVertexShader);
    glAttachShader(shaderProgram, testFragmentShader);
    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &wasSuccess);

    if (!wasSuccess) {

        char compileMessage[500];

        glGetProgramInfoLog(shaderProgram, 500, NULL, message);

        strcat(compileMessage, "The following error occurred on gpu:\n\n");
        strcat(compileMessage, message);

        SEE::Logger::printError(message);
        SEE::Logger::printFatal("Couldn't link shader program!");
        
    }


    glDeleteShader(testVertexShader);
    glDeleteShader(testFragmentShader);


    SEE::Logger::printInfo("Shaders loaded successfully!");


    // Loop until the user closes the window
    while (!glfwWindowShouldClose(this->window)) {

        // Render here
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);
        glBindVertexArray(testVao);
        glDrawArrays(GL_TRIANGLES, 0, 3);

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