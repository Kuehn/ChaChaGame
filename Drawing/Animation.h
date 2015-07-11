#pragma once
#ifndef _ANIMATION_H
#define _ANIMATION_H

#include <vector>
#include "Frame.h"
class Animation
{
public:
	Animation();
	void render();

	~Animation();
private:
	std::vector<Frame> *frames;
	int curFrame;
};

#endif _ANIMATION_H // !
