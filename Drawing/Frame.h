#pragma once
#ifndef _FRAME_H
#define _FRAME_H
#include "Sprite.h"
class Frame
{
public:
	Frame(Sprite spr, int length);
	bool render();
	~Frame();
private:
	int numDisplayed;
	int length;
	Sprite spr;

	
};
#endif _FRAME_H
