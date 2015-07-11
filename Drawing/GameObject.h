#pragma once
#ifndef _GAME_OBJECT_H
#define _GAME_OBJECT_H
#include "Animation.h"
#include "GL\glew.h"
#include <iostream>
class GameObject
{
public:
	//virtual void GameObj();
	//GameObject();
	void update();
	void render();
	void render(int,int,int, int, int);
	float getX();
	float getY();
	float getSizeX();
	float getSizeY();
	void setX(float);
	void setY(float);
	//~GameObject();
protected:
	float x;
	float y;
	//float sizeX;
	//float sizeY;
	Sprite *spr;
	void init(float, float, float, float, float, float, float);
	//Animation anim;
};
#endif _GAME_OBJECT_H

