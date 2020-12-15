// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

// add headers that you want to pre-compile here
#include "Application.h"
#include "Logger.h"
#include "Render.h"

#ifdef MAC
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#endif

#ifdef WIN32
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#endif

#endif //PCH_H
