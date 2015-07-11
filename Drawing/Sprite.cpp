#include "Sprite.h"


#include<GLFW\glfw3.h>



Sprite::Sprite(){}
Sprite::Sprite(float x, float y,float r, float g, float b, float sizeX, float sizeY)
{
	this->x = x;
	this->y = y;
	this -> r = r;
	this->g = g;
	this->b = b;
	this->sizeX = sizeX;
	this->sizeY = sizeY;

}
Sprite::~Sprite()
{
}

void Sprite::render(){
	glBegin(GL_LINES);
	glColor3ub(255, 0, 0);
	glVertex2f(0.0f, 0.0f);
	glColor3ub(0, 0, 255);
	glVertex2f(800.0f, 600.0f);
	glEnd();
	glBegin(GL_LINES);
	glColor3ub(255, 0, 0);
	glVertex2f(-1.0f, 0.0f);
	glColor3ub(0, 0, 255);
	glVertex2f(400.0f, 600.0f);
	glEnd();
	glColor3f(r, g, b);
	glBegin(GL_QUADS);
	{//WHERE DRAWING GOES.. DONT NEED curly braces but looks organized
		std::cout << "START OF DRAWING" << std::endl;
		std::cout << r << std::endl;
		std::cout << g << std::endl;
		std::cout << b << std::endl;
		std::cout << sizeX << std::endl;
		std::cout << sizeY << std::endl;
		glVertex2f(0,0);
		glVertex2f(0, sizeY); //switch to .1 for different effect
		glVertex2f(sizeX, sizeY);
		glVertex2f(sizeX, 0);
	}
	glEnd();
}
float Sprite::getX(){
	return x;
}
float Sprite::getY(){
	return y;
}
float Sprite::getSizeX(){
	return this->sizeX;
}
float Sprite::getSizeY(){
	return this->sizeY;
}
void Sprite::setSizeX(float sX){
	this->sizeX = sX;
}
void Sprite::setSizeY(float sY){
	this->sizeY = sY;
}
//void Sprite::setX(float newX){
//	x = newX;
//}
//void Sprite::setY(float newY){
//	y = newY;
//}