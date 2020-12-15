#pragma once
#include "pch.h"

namespace SEE {
	class Logger {
	public:

		/// Prints an info's text into the console.
		/// Parameters:
		/// - text: The text to be printed into the console.
		static void printInfo(const char* text);
		static void printInfo(float text);

		/// Prints an error's text into the console.
		/// Parameters:
		/// - text: The text to be printed into the console.
		static void printError(const char* text);
		static void printError(float text);

		/// Prints a fatal's text into the console.
		/// Parameters:
		/// - text: The text to be printed into the console.
		static void printFatal(const char* text);
		static void printFatal(float text);

	};
}