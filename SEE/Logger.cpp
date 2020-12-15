#include "Logger.h"
#include <iostream>
#include "Core.h"

void SEE::Logger::printInfo(const char* text) {
	std::cout << "[INFO] " << text << std::endl;
}

void SEE::Logger::printInfo(float text) {
	std::cout << "[INFO] " << text << std::endl;
}

void SEE::Logger::printError(const char* text) {
	std::cout << "[ERROR] " << text << std::endl;
}

void SEE::Logger::printError(float text) {
	std::cout << "[ERROR] " << text << std::endl;
}

void SEE::Logger::printFatal(const char* text) {
	std::cout << "[FATAL] " << text << std::endl;
	SEE::Core::stop();
}

void SEE::Logger::printFatal(float text) {
	std::cout << "[FATAL] " << text << std::endl;
	SEE::Core::stop();
}