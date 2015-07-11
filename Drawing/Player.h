#pragma once
#ifndef _PLAYER_H
#define _PLAYER_H
#include "GameObject.h"
#include <iostream>
#include<GLFW\glfw3.h>
#include "World.h"
class Player: public GameObject
{
public:
	Player(int,int,int,float,float,Tile*);
	~Player();
	Tile *playerTile;
	int red;
	int green;
	int blue;
	void getInput(GLFWwindow *window, World *world);
	float getSpeed();
	const float SIZE = 32;
	float getX(void);
	float getY(void);
	float cameraY;
	float cameraX;
	void setRGB(int, int, int);
protected:
	void move(float moveX, float moveY);
	Sprite *spr;
};


#endif _PLAYER_H