#include "Frame.h"


Frame::Frame(Sprite spr, int length)
{
	this -> spr = spr;
	this ->length = length;
	numDisplayed = 0;
}
bool Frame::render(){
	spr.render();
	numDisplayed++;
	
	if (numDisplayed >= length){
		numDisplayed = 0;
		return true;
	}
	return false;
}

Frame::~Frame()
{
}
