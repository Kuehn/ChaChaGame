/*
 * Tile.cpp
 *
 *  Created on: Nov 6, 2014
 *      Author: Josh
 */

#include "Tile.h"
#include <string>



Tile::Tile()
{
	x = -1;
	y = -1;
	image = '.';
	opacity = false;
	passable = true;
	movementCost = 1;
}

Tile::Tile(int r,int g, int bl,int a, int b)
{
	red = r;
	green = g;
	blue = bl;
	x =a;
	y = b;
	image = 'x';
	opacity = false;
	passable = true;
	movementCost = 1;
}

Tile::~Tile()
{
	// TODO Auto-generated destructor stub
}

int Tile::getX()
{
	return x;
}

int Tile::getY()
{
	return y;
}

char Tile::getImage()
{
	return image;
}

int Tile::getMovementCost()
{
	return movementCost;
}

bool Tile::getPassable()
{
	return passable;
}

void Tile::setSize(int inSize){
	size = inSize;
}
int Tile::getSize(){
	return size;
}
void Tile::setX(int inX)
{
	x = inX;
}

void Tile::setY(int inY)
{
	y = inY;
}

void Tile::setImage(char inImage)
{
	image = inImage;
}

void Tile::setPassable(bool inPassable)
{
	passable = inPassable;
}

void Tile::setMovementCost(int inCost)
{
	movementCost = inCost;
}
void Tile::setRGB(int r, int g, int b){
	red = r;
	green = g;
	blue = b;
}
void Tile::setRendXLoc(int newXLoc){
	rendX = newXLoc;
}
void Tile::setRendYLoc(int newYLoc){
	rendY = newYLoc;
}
int Tile::getRendX(){
	return rendX;
}
int Tile::getRendY(){
	return rendY;
}
void Tile::render(){
	glColor3f(red, green, blue);
	glBegin(GL_QUADS);
	{//WHERE DRAWING GOES.. DONT NEED curly braces but looks organized
		glVertex2f(0, 0);
		glVertex2f(0, size); 
		glVertex2f(size, size);
		glVertex2f(size, 0);
	}
	glEnd();
}