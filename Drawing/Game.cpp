#include "Game.h"

Game::Game()
{
	objects = new std::vector <GameObject>();

	world = new World(20,20);
	player = new Player(0,4,0,world->map[3][3].getX(), world->map[3][3].getY(),world->findTile(3,3));
	//temporary way of putting player on specific tile
	player->setX(player->playerTile->getRendX());
	player->setY(player->playerTile->getRendY());
	//player->setX(world->map[1][0].getRendX());
	//player->setY(world->map[1][0].getRendY());
	//
	std::vector<GameObject>::iterator it;
	it = objects->begin();
	objects->insert(it, *player);
}

void Game::getInput(GLFWwindow *window){
	player->getInput(window,world);
}

void Game::update(){
	int i = 0;
	for each (GameObject go in *objects){
		i++;
		std::cout << "HERES I: " << i << std::endl;
		go.update();
	}
}

void Game::render(){
	std::cout << "GAME OBJECTS VECTOR SIZE: " << objects->size() << std::endl;
	std::cout << "CamX: " << player->cameraX << std::endl;
	std::cout << "CamY: " << player->cameraY << std::endl;
	for (int i = world->getMaxY() - 1; i >= 0; i--){
		for (int j = 0; j < world->getMaxX(); j++){
			glPushMatrix();
			{										   //THIS JUST ADDED CAMERAX nad CAMERAY
				glTranslatef(world->map[i][j].getRendX()+player->cameraX, world->map[i][j].getRendY()+player->cameraY, 0);
				world->map[i][j].render();
			}//Curly braces not needed
			glPopMatrix();
		}
	}

//	for each(GameObject go in *objects)
//	{
//		go.render();
//	}
	player->playerTile->setRGB(0, 4, 0);
	player->setRGB(0, 4, 0);
	//player->setRGB(0, 4, 0);
}
Game::~Game()
{
}
