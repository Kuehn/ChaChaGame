#include "Player.h"


Player::Player(int r, int g, int b, float x, float y,Tile *tile)
{
	this->playerTile = tile;
	std::cout << "IS IT WORKING?" << std::endl;
	//std::cout << "SIZE:" + SIZE << std::endl;
	cameraX = x;
	cameraY = y;
	this->red = r;
	this->green = g;
	this->blue = b;
	//init(x, y, 1, 55.0, 0.25,SIZE,SIZE); //IN GAME OBJECT
}


Player::~Player()
{
}
void Player::setRGB(int r, int g, int b)
{	
	red = r;
	green = g;
	blue = b;
}
void Player::getInput(GLFWwindow *window, World *world)
{
	Tile *tempTile;
	int aKey = glfwGetKey(window, GLFW_KEY_A);
	if (aKey == GLFW_PRESS)
	{
 		std::cout << "PRESSED THE SPACE KEY" << std::endl;
		//tempTile = world->getStep(*playerTile, 4); //8 is west
		tempTile = world->getStep(*playerTile, 8); //4 is south
		playerTile = tempTile;
		//playerTile->setX(tempTile->getRendX());
		//playerTile->setY(tempTile->getRendY());
		//playerTile->setRendXLoc(tempTile->getRendX());
		//playerTile->setRendYLoc(tempTile->getRendY());
		//this->x = tempTile->getX();
		//this->y = tempTile->getY();
		this->x = tempTile->getRendX();
		this->y = tempTile->getRendY();
		//move(-1, 0);
	}
	int wKey = glfwGetKey(window, GLFW_KEY_W);
	if (wKey == GLFW_PRESS)
	{
		std::cout << "W KEY PRESSED" << std::endl;
		std::cout << "X: " << getX() << std::endl;
		std::cout << "Y: " << getY() << std::endl;
		std::cout << "stopped" << std::endl;
		//tempTile = world->getStep(*playerTile, 8); //1 is north
		tempTile = world->getStep(*playerTile, 1); //1 is north
		playerTile = tempTile;
		//this->x = tempTile->getX();
		//this->y = tempTile->getY();
		this->x = tempTile->getRendX();
		this->y = tempTile->getRendY();
		std::cout << "PLAYERS NEW X: " << x << std::endl;
		std::cout << "PLAYERS NEW Y: " << y << std::endl;
		std::cout << "YE" << std::endl;
		//move(0, -1);
	}
	int sKey = glfwGetKey(window, GLFW_KEY_S);
	if (sKey == GLFW_PRESS)
	{
		//tempTile = world->getStep(*playerTile, 2); //4 is south
		tempTile = world->getStep(*playerTile, 4); //4 is south
		playerTile = tempTile;
		//this->x = tempTile->getX();
		//this->y = tempTile->getY();
		this->x = tempTile->getRendX();
		this->y = tempTile->getRendY();
	}
	int dKey = glfwGetKey(window, GLFW_KEY_D);
	if (dKey == GLFW_PRESS)
	{
		//tempTile = world->getStep(*playerTile, 1); //2 is east
		tempTile = world->getStep(*playerTile, 2); //4 is south
		playerTile = tempTile;
		//this->x = tempTile->getX();
		//this->y = tempTile->getY();
		this->x = tempTile->getRendX();
		this->y = tempTile->getRendY();
	}
	int vKey = glfwGetKey(window, GLFW_KEY_V);
	if (vKey == GLFW_PRESS){
		std::vector <Tile*>temp = world->getInBox(playerTile->getX()-2, playerTile->getY()-2,playerTile->getX()+2,playerTile->getY()+2);
		std::cout << "VECTOR SIZE" << temp.size() << std::endl;
		for (int i = 0; i < temp.size(); i++){//probably a problem here I believe i need a double array
			//for (int j = 0; j < temp[i].size(); )
			temp[i]->setRGB(0, 0, 4);
		}
	}

	int upArrow = glfwGetKey(window, GLFW_KEY_UP);
	if (upArrow == GLFW_PRESS){
		std::cout << "cameraY" << cameraY << std::endl;
		cameraY += getSpeed() * 1;
		std::cout << "cameraY" << cameraY << std::endl;
	}
	int downArrow = glfwGetKey(window, GLFW_KEY_DOWN);
	if (downArrow == GLFW_PRESS){
		cameraY += getSpeed() * -1;
	}
	int leftArrow = glfwGetKey(window, GLFW_KEY_LEFT);
	if (leftArrow == GLFW_PRESS){
		cameraX += getSpeed() * 1;
	}
	int rightArrow = glfwGetKey(window, GLFW_KEY_RIGHT);
	if (rightArrow == GLFW_PRESS){
		cameraX += getSpeed() * -1;
	}
	//if (glfwGetKey(window, GLFW_KEY_SPACE)){ //JUST TESTING OUT A PRESSED BUTTON FUNCTIONALITY
	//cout << "BOOOOOOYAH" << std::endl;
	//CHANGE DRAWING HERE? FOR FUN
	//}
	//if (glfw)
}
float Player::getX(){
	return x;
}
float Player::getY(){
	return y;
}
void Player::move(float moveX, float moveY)
{
	//spr->setX(getSpeed() * moveX);
	//spr->setY(getSpeed() * moveY);
	this->x += getSpeed() * moveX;
	this->y += getSpeed() * moveY;
	//setY(y);
	std::cout << "VALUE OF X" << std::endl;
	std::cout << x << std::endl;
	std::cout << "VALUE OF Y" << std::endl;
	std::cout << y << std::endl;
	std::cout << "YEP" << std::endl;
}
float Player::getSpeed(){
	return 12.0;
}