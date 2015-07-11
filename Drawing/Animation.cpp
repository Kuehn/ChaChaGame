#include "Animation.h"


Animation::Animation()
{
	frames = new std::vector<Frame>();
}

void Animation::render(){
	Frame temp = frames->at(curFrame);
	if (temp.render()){
		curFrame++;
		curFrame %= frames->size();
	}
}

Animation::~Animation()
{
}
