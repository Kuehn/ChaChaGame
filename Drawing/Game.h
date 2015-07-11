#pragma once
#ifndef _GAME_H
#define _GAME_H
#include <vector>
#include "GameObject.h"
#include<GLFW\glfw3.h>
#include "Player.h"
#include "World.h"
class Game
{
public:
	Game();
	~Game();
	void getInput(GLFWwindow *window);
	void update();
	void render();
public:
	std::vector<GameObject> *objects;
	Player *player;
	World *world;
};

#endif _GAME_
