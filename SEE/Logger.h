#pragma once
#include "pch.h"

namespace SEE {
	class Logger {
	public:

		/// Prints an info's text into the console.
		/// Parameters:
		/// - text: The text to be printed into the console.
		static void printInfo(const char* text);

		/// Prints an error's text into the console.
		/// Parameters:
		/// - text: The text to be printed into the console.
		static void printError(const char* text);

		/// Prints a fatal's text into the console.
		/// Parameters:
		/// - text: The text to be printed into the console.
		static void printFatal(const char* text);

	};
}