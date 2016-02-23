#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <GL/glew.h>

#include "display.h"
#include "settings.h"

#define SCREEN_WIDTH GetSystemMetrics(SM_CXSCREEN)
#define SCREEN_HEIGHT GetSystemMetrics(SM_CYSCREEN)

class Shader
{
public:
	GLuint Program;
	// Constructor generates the shader on the fly
	Shader(const GLchar* vertexPath, const GLchar* fragmentPath, Display* display)
	{
		// 1. Retrieve the vertex/fragment source code from filePath
		std::string vertexCode;
		std::string fragmentCode;
		std::ifstream vShaderFile;
		std::ifstream fShaderFile;
		// ensures ifstream objects can throw exceptions:
		vShaderFile.exceptions(std::ifstream::badbit);
		fShaderFile.exceptions(std::ifstream::badbit);
		try
		{
			// Open files
			std::cout << "Read Vertex Shader\n";
			vShaderFile.open(vertexPath);
			std::cout << "Read Fragment Shader\n";
			fShaderFile.open(fragmentPath);
			std::stringstream vShaderStream, fShaderStream;
			// Read file's buffer contents into streams
			vShaderStream << vShaderFile.rdbuf();
			fShaderStream << fShaderFile.rdbuf();
			// close file handlers
			vShaderFile.close();
			fShaderFile.close();
			// Convert stream into string
			vertexCode = vShaderStream.str();
			fragmentCode = fShaderStream.str();
		}
		catch (std::ifstream::failure e)
		{
			std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
			glfwTerminate();
			system("pause");
			display->Close();
		}
		const GLchar* vShaderCode = vertexCode.c_str();
		const GLchar * fShaderCode = fragmentCode.c_str();
		// 2. Compile shaders
		GLuint vertex, fragment;
		GLint success;
		GLchar infoLog[512];
		// Vertex Shader
		std::cout << "Compile Vertex Shader\n";
		vertex = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex, 1, &vShaderCode, NULL);
		glCompileShader(vertex);
		// Print compile errors if any
		glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertex, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
			glfwTerminate();
			system("pause");
			display->Close();
		}
		// Fragment Shader
		std::cout << "Compile Fragment Shader\n";
		fragment = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment, 1, &fShaderCode, NULL);
		glCompileShader(fragment);
		// Print compile errors if any
		glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragment, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
			glfwTerminate();
			system("pause");
			display->Close();
		}
		// Shader Program
		std::cout << "Link Shaders\n";
		this->Program = glCreateProgram();
		glAttachShader(this->Program, vertex);
		glAttachShader(this->Program, fragment);
		glLinkProgram(this->Program);
		// Print linking errors if any
		glGetProgramiv(this->Program, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(this->Program, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
			glfwTerminate();
			system("pause");
			display->Close();
		}
		// Delete the shaders as they're linked into our program now and no longer necessery
		glDeleteShader(vertex);
		glDeleteShader(fragment);

	}

	//Pass screenResolution and spriteResolution to Shader
	void setResolutions(GLuint width, GLuint height, GLuint textureWidth, GLuint textureHeight, GLuint fieldSizeInPX) {
		GLuint scrRLocation = glGetUniformLocation(this->Program, "screenResolution");
		GLuint sprRLocation = glGetUniformLocation(this->Program, "spriteResolution");
		GLuint scbLocation = glGetUniformLocation(this->Program, "screenBorder");
		GLuint fcLocation = glGetUniformLocation(this->Program, "tileSize");
		glUseProgram(this->Program);
		glUniform2f(scrRLocation, (GLfloat) width / 2, (GLfloat) height / 2);
		glUniform2f(sprRLocation, (GLfloat) textureWidth, (GLfloat) textureHeight);
		glUniform2f(scbLocation, (GLfloat) (width - fieldSizeInPX) / 2, (GLfloat) (height - fieldSizeInPX) / 2);
		glUniform1f(fcLocation, (GLfloat) fieldSizeInPX / FIELDSIZE);
	}

	// Uses the current shader
	void Use()
	{
		glUseProgram(this->Program);
	}
};

