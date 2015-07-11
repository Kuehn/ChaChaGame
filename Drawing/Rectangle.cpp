#include "Rectangle.h"


Rectangle::Rectangle(int x, int width, int y, int height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}


Rectangle::~Rectangle()
{
}
int Rectangle::getX(){
	return this->x;
}
int Rectangle::getY(){
	return this->y;
}
int Rectangle::getWidth()
{
	return this->width;
}
int Rectangle::getHeight()
{
	return this->height;
}
int Rectangle::getArea()
{
	return this->width / this->height;
}
bool Rectangle::intersects(Rectangle r2)
{
	if (this->getX() < r2.getWidth() || this->getWidth() > r2.getX() || this->getY() < r2.getHeight() || this->getHeight() > r2.getY())
	{
		return false;
	}
	else
	{
		return true;
	}
}