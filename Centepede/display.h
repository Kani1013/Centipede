#pragma once

#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include <string>
#include <iostream>
#include "settings.h"

class Display
{
public:
	Display(int width, int height, const std::string& title);

	void Update();
	bool isClosed();
	void Close();

	virtual ~Display();
	GLFWwindow* window;

private:
	Display(const Display& other) {}
	void operator=(const Display& other) {}

	void Clear(float r, float g, float b, float a);

	bool windowIsClosed;
};