#pragma once

#include "bx/platform/window.hpp"

#include <GLFW/glfw3.h>

class WindowGLFW
{
public:
	static GLFWwindow* GetWindowPtr();
};