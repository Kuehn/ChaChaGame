#ifndef _SHADERS_UTILS_
#define _SHADERS_UTILS_
#include<gl\glew.h>
#include<GLFW\glfw3.h>
#include<fstream>
#include<streambuf>
#include<iostream>
class ShadersUtils
{
public:
	static GLuint createShaderFromFile(const GLchar* path,GLenum shaderType);
	//static GLuint createProgramFromShaders()
};

#endif