//#define GLFW_INCLUDE_GLCOREARB
//#include<GL\glew.h> //GL will complain inf glew.h is not first.. idk why.
#include<gl\glew.h>
#include<iostream>
#define GLFW_STATIC
//#include<SDL2\SDL.h>
#include<GLFW\glfw3.h>
//#include<GL\freeglut.h>
#include<ogldev_math_3d.h>
#include<glm\glm.hpp>
#include "ShadersUtils.h"
#include "Game.h"


GLuint VBO; //is a handle fo the vertex buffer object
GLuint VAO;
Game *game;

void initializeDisplay(int argc, char **argv,GLint windowWidth, GLint windowHeight){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	std::cout << "WIDTH:" << std::endl;
	std::cout << windowWidth << std::endl;
	std::cout << "Height:" << std::endl;
	std::cout << windowHeight << std::endl;

	glOrtho(0, windowWidth, windowHeight,0, -1, 1);//SET ORTHO TO THE DISPLAY WIDTH AND HEIGHT ASAP!!!!!!!!!!!
	glMatrixMode(GL_MODELVIEW);
	glDisable(GL_DEPTH_TEST);//Saves us from having opengl constantly checking depth.
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

}
void initGame(){
	cout << "Starting Game Initialization" << std::endl;
	game = new Game();
	cout << "GAME INITIALIZED" << std::endl;
}
void getInput(GLFWwindow *window){
	game->getInput(window);
}
void update(){
	game->update();
}

//ORDR FOR DRAWING SO FAR//
//GLPUSHMATRIX -translate(x,y,z)
//GL BEGIN - draw vertices
//GL END
//GLPOPMATRIX
//Load Identity
//glBindVertexArray(VAO)
//glDrawArray
//glBindVertexArray(NULL
//glfwPoolEvents();
//glfwSwapBuffers(window)

void render(GLFWwindow *window, GLint windowWidth, GLint windowHeight){
	//glClear(GL_COLOR_BUFFER_BIT);
    //glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	game->render();//THIS MAY BE IN THE WRONG SPOT//
	glLoadIdentity();
	glfwSwapBuffers(window);
//THEN NEED TO UPDATE??MAKE SURE WE ARE UPDATING, 17:42 first video//
	std::cout << "VAO" << std::endl;
	std::cout << VAO << std::endl;
	std::cout << "VBO" << std::endl;
	std::cout << VBO << std::endl;
	glfwPollEvents();
}
void gameLoop(GLFWwindow *window, GLint windowWidth, GLint windowHeight){
	cout << "Entereing Game Loop" << std::endl;
	while (!glfwWindowShouldClose(window)){//GAME LOOP//
		///SHOULD JUST BE//
		//cout << "Getting input" << std::endl;
		getInput(window);
		//cout << "Getting update" << std::endl;
		update();
		//cout << "Getting render" << std::endl;
		render(window, windowWidth,windowHeight);
		//glDrawArrays(GL_QUADS, 0, 24);

	}
}

int main(int argc, char** argv){
	GLint glfwStatus = glfwInit(); //TO  use most GLFW functions we need to initiate this
	if (glfwStatus != GL_TRUE){
		cout << "FAILED TO LOAD GLFW..bummer" << std::endl;
		glfwTerminate();
		return 1;
	}
	GLFWwindow *window = glfwCreateWindow(800, 800, "BITCH PLEASE, I GOT THIS", glfwGetPrimaryMonitor(), NULL);//Makes FULL SCREEN
	
	//GLFWwindow *window = glfwCreateWindow(600, 600, "BITCH PLEASE, I GOT THIS", NULL, NULL);

	/////CHECK IF WINDOW HAS BEEN CREATED//////
	if (window == NULL){
		cout << "FAILED TO CREATE WINDOW" << std::endl;
		return -1;
		glfwTerminate();
	}
	/////END WINDOW CREATION CHECK///////
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	glfwMakeContextCurrent(window);
	cout << glGetString(GL_VERSION) << std::endl;
	////INITIALIZE GLEW AND CHECK FOR SUCCESS//////
	GLenum res = glewInit(); //Initialize Glew and check for errors with initialization
	if (res != GLEW_OK){
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
		return 0;
	}
	////END GLEW////
	GLint windowWidth, windowHeight;
	glfwGetWindowSize(window, &windowWidth, &windowHeight);
	initializeDisplay(argc, argv, windowWidth, windowHeight);
	initGame();
	gameLoop(window,windowWidth, windowHeight);
	//CLOSING GAME//
	delete(game);
	//glDeleteProgram(shaderProgram);
	glDeleteVertexArrays(1, &VAO);
	//	glDeleteShader(fragmentShader);
	glDeleteBuffers(1,&VBO);
	//  glDeleteShader(vertexShader);
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}