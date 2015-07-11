#include "GameObject.h"

//GameObject::GameObject()
//{

//}


//GameObject::~GameObject()
//{
//}

void GameObject::update(){

}
void GameObject::render(){
	std::cout << "RENDERED X BEFORE MATRIX " << getX() << std::endl;
	std::cout << "RENDERED Y BEFORE MATRIX " << getY() << std::endl;

	glPushMatrix();
	{
	//std::cout << "PUSHING MATRIX" << std::endl;
		std::cout << "RENDERED X" << std::endl;
		std::cout << getX() << std::endl;
		std::cout << "RENDERED Y" << std::endl;
		std::cout << getY() << std::endl;
		//glTranslatef(spr->getX(), spr->getY(), 0);
		glTranslatef(getX(),getY(), 0);
		spr->render(); //PROBABLY dont need the "this ->"
	}//Curly braces not needed
	glPopMatrix();
}
void GameObject::render(int x, int y, int r, int g, int b){
	glPushMatrix();
	{
		glTranslatef(x, y, 0);
	}
}
float GameObject::getX(){
	return x;
}
float GameObject::getY(){
	return y;
}
void GameObject::setX(float newX){
	x = newX;
}
void GameObject::setY(float newY){
	y = newY;
}
float GameObject::getSizeX(){
	return spr->getSizeX();
	//return this->sizeX;
}
float GameObject::getSizeY(){
	return spr->getSizeY();
}
void GameObject::init(float x, float y, float r, float g, float b, float sizeX, float sizeY)
{
	//this->x = x;
	//this->y = y;
	std::cout << "!!!!!!!!!X!!!!!!" << std::endl;
	std::cout << x << std::endl;
	std::cout << "!!!!!!!!!Y!!!!!!" << std::endl;
	std::cout << y << std::endl;
	std::cout << "SIZEX" << std::endl;
	std::cout << sizeX << std::endl;
	std::cout << "sizeY" << std::endl;
	std::cout << sizeY << std::endl;
	spr = new Sprite(x,y,r, g, b, sizeX, sizeY);
}