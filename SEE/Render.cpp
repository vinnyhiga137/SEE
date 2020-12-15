#include "Render.h"
#include <fstream>
#include <string>

SEE::Render* SEE::Render::instance = nullptr;

SEE::Render::Render() {
    this->shaderProgram = 0;
    this->testVao = 0;
}

SEE::Render::~Render() {

}

void SEE::Render::SetupShaderProgram(
    const char* vertexFile, 
    const char* fragFile,
    SEE::Sprite* sprite) {


    // Generating a buffer where will be setted the values related to a point
    // in 3d space, like it's position & color
    unsigned int testVbo = 0;
    glGenBuffers(1, &testVbo);

    glGenVertexArrays(1, &(this->testVao));

    glBindVertexArray(this->testVao);

    std::vector<float> vecVertices = *(sprite->vertices);
    float* vertices = &vecVertices[0];

    glBindBuffer(GL_ARRAY_BUFFER, testVbo); // Generating ID for that buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * sprite->vertices->capacity(), vertices, GL_STATIC_DRAW); // Copying data into that buffer

    // Loading the vertex shader
    SEE::Logger::printInfo("Loading shaders files!");

    char shaderPath[200] = { '\0' };
    std::string vertexSourceLines = "";
    std::string fragmentSourceLines = "";
    std::string fileLine;

    strcpy_s(shaderPath, GET_SHADER_PATH);
    strcat_s(shaderPath, vertexFile);

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
    strcpy_s(shaderPath, GET_SHADER_PATH);
    strcat_s(shaderPath, fragFile);

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

        strcat_s(compileMessage, "The following error occurred on gpu:\n\n");
        strcat_s(compileMessage, message);

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

        strcat_s(compileMessage, "The following error occurred on gpu:\n\n");
        strcat_s(compileMessage, message);

        SEE::Logger::printError(message);
        SEE::Logger::printFatal("Couldn't compile vertex shader!");
    }


    //unsigned int shaderProgram;
    //shaderProgram = glCreateProgram();
    this->shaderProgram = glCreateProgram();


    SEE::Logger::printInfo("Linking shader program!");


    glAttachShader(this->shaderProgram, testVertexShader);
    glAttachShader(this->shaderProgram, testFragmentShader);
    glLinkProgram(this->shaderProgram);

    glGetProgramiv(this->shaderProgram, GL_LINK_STATUS, &wasSuccess);

    if (!wasSuccess) {

        char compileMessage[500];

        glGetProgramInfoLog(this->shaderProgram, 500, NULL, message);

        strcat_s(compileMessage, "The following error occurred on gpu:\n\n");
        strcat_s(compileMessage, message);

        SEE::Logger::printError(message);
        SEE::Logger::printFatal("Couldn't link shader program!");

    }


    glDeleteShader(testVertexShader);
    glDeleteShader(testFragmentShader);


    SEE::Logger::printInfo("Shaders loaded successfully!");
}

void SEE::Render::DrawContent() {

    glUseProgram(this->shaderProgram);
    glBindVertexArray(this->testVao);
    glDrawArrays(GL_TRIANGLES, 0, 3);

}

SEE::Render* SEE::Render::GetInstance() {

    if (SEE::Render::instance == nullptr) {
        SEE::Render::instance = new SEE::Render();
    }

    return SEE::Render::instance;
}