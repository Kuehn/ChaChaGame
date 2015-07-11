#pragma once
#ifndef _SPRITE_H
#define _SPRTIE_H
#include<gl\glew.h>
#include<iostream>
class Sprite
{
public:
	Sprite();
	Sprite(float, float,float,float,float ,float,float);
	~Sprite();
	void render();
	//void setX(float);
	//void setY(float);
	float getX();
	float getY();
	float getSizeX();
	float getSizeY();
	void setSizeX(float);
	void setSizeY(float);

protected:
	float x;
	float y;
	float r;
	float g;
	float b;
	float sizeX;
	float sizeY;

};
#endif _SPRITE_H
