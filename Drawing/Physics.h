#pragma once
#ifndef _PHYSICS_H
#define _PHYSICS_H
#include "GameObject.h"
#include "Rectangle.h"
class Physics
{
public:
	Physics();
	~Physics();
	bool checkCollision(GameObject, GameObject);
};

#endif _PHYSICS_H