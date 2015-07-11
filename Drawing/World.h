/*
 * World.h
 *
 *  Created on: Nov 8, 2014
 *      Author: Josh
 */

#ifndef WORLD_H_
#define WORLD_H_

//#include "Client.h"
#include "Tile.h"
#include <string>
#include <vector>

class World
{
int maxX, maxY;

//Client* clients;
void changeCoordinates(int& x, int xMod, int& y, int yMod);
public:
	Tile** map;
	World(int, int);
	virtual ~World();

	int getRowCount();
	int getColoumnCount();
	//
	int getMaxX();
	int getMaxY();
	//
	Tile* findTile(int x, int y);							//Finds the tile at a certain x,y coordinate
	Tile* getStep(Tile& start, int direction);				//Finds the tile next to a reference tile using a direction (diagonal directions are acceptable)
	std::vector <Tile*> getInDiamond(Tile& mid, int range, int nullDirection = 0);	//Finds a list of tiles in a diamond around a reference tile
	std::vector <Tile*> getInMoveRange(Tile& mid, int range, int nullDirection = 0);	//Finds the possible tiles something can move to.
	std::vector <Tile*> getInView(Tile& center, int range);							//Finds the box of a persons view
	std::vector <Tile*> getInBox(int minX, int minY, int maxX, int maxY);				//Finds the tiles in a box
	std::vector <Tile*> getInRow(int row);								//Finds all the tiles in a row. y is row
	std::vector <Tile*> getInColumn(int collumn);						//Finds all the tiles in a column. x is column
	std::vector <Tile*> getInLine(Tile& start, int length, int direction);		//Finds all tiles in a line (Directions can be diagonal)
	std::vector <Tile*> getInCross(Tile& start, int length);	//Finds all the tiles in a cross.
	void printMap();

};

#endif /* WORLD_H_ */
