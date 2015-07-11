/*
 * World.cpp
 *
 *  Created on: Nov 8, 2014
 *      Author: Josh
 */

#include "World.h"
#include "Tile.h"
#include <iostream>
#include <new>
#include <string>
#include <fstream>
#include <vector>

//Basic defines for directions. This makes combining directions easy. (NORTHEAST would just be 3.... etc)
#define NORTH 1
#define EAST 2
#define SOUTH 4
#define WEST 8


World::World(int inX, int inY)		//Basic constructor. In the future this should take in a text file or something and convert that into a map. As of now just makes a boring map.
{
	maxX = inX; //Maximum width of map
	maxY = inY; //Maximum height of map
	int size = 32; //size of tiles, just temporarily here.
	map = new Tile*[maxX];
	for(int i = 0 ; i < maxX ; i++)
	{
		map[i] = new Tile[maxY];
	}
	int jumpY = 0;//variable to measure change
	int jumpX = 0 - size;
	for(int x = 0 ; x <maxX ; x++)
	{ 
		jumpY = 0;
		jumpX = jumpX + size;
		for(int y = 0 ; y < maxY ; y++)
		{
			jumpY = jumpY - size; //put this at bottom of this for loop if we keep this way
			map[x][y].setX(x + 1);//USED TO BE THIS
			map[x][y].setY(y + 1);//Same as above
			map[x][y].setRendXLoc(jumpX);
			map[x][y].setRendYLoc(jumpY);
			map[x][y].setSize(size);
			map[x][y].setRGB(4, 0, 0);
		}
	}
	map[0][0].setRGB(0, 0, 4); //SET START FIRST TILE BLUE.. for reference on drawing direction
}


World::~World()					//yeah....
{
	// TODO Auto-generated destructor stub
}

int World::getMaxX(){
	return maxX;
}
int World::getMaxY(){
	return maxY;
}
Tile* World::getStep(Tile& start, int direction)		//Finds the tile just a step away from a function. Could add diagonals in the future.
{
	int x = start.getX();
	int y = start.getY();
	std::cout << "X IS: " << x << std::endl;
	std::cout << "Y IS: " << y << std::endl;



	//Here is the bitflag of doing things, this should (theoretically make things faster, and also make it easier to handle multiple direction arguments (North east would just be 3, or NORTH + EAST)
	//Checks to see if
	if(direction & NORTH)
	{
		y++;
	}
	if(direction & EAST)
	{
		x++;
	}
	if(direction & SOUTH)
	{
		y--;
	}
	if(direction & WEST)
	{
		x--;
	}
						//Checking to see if we are still in bounds.
	if(y > maxY)
		y = maxY;
	else if(y < 1)
		y = 1;

	if(x > maxX)
		x = maxX;
	else if(x<1)
		x = 1;

	return &map[x-1][y-1];
	/*Old way of doing things, much easier to read so I kept it as a reference. Bit flags, though are super cool
	Tile* output = 0;		//This should be nullptr instead of zero - but that is not working, maybe my version is wrong
	switch(direction)
	{
		case NORTH:
			if(y+1 >= maxY)
			{
				break;				//Possibly change this to output = &start; (So you return the same tile.)
			}
			output = &map[x][y+1];
			break;
		case EAST:
			if(x+1 >= maxX)
			{
				break;				//Same here
			}
			output = &map[x+1][y];
			break;
		case SOUTH:
			if(y-1 < 0)
			{
				break;				//and here
			}
			output = &map[x][y-1];
			break;
		case WEST:
			if(x-1 < 0)
			{
				break;
			}
			output = &map[x-1][y];
			break;
	}*/

}

void World::changeCoordinates(int& x, int xMod, int& y, int yMod = 0)	//may have to have minimums zero, and maxes >=. Think more on this later if we get errors.
{
	x+= xMod;
	y+= yMod;

	if(x < 1) x = 1;
	if(x > maxX) x = maxX;
	if(y < 1) y = 1;
	if(y> maxY) y = maxY;

}


Tile* World::findTile(int x, int y)	//TODO check to see if out of bounds
{
	std::cout << "\nWe called find tile x: " << x << " y: " << y;

	return &map[x-1][y-1];
}


void World::printMap()
{
	std::cout << "maxX:" << maxX;
	std::cout << "maxY:" << maxY;
	for(int y = maxY-1 ; y >= 0 ; y--)
	{
		std::cout << "\n";
		for(int x = 0 ; x < maxX ; x++)
		{
			std::cout << map[x][y].getImage();
		}
	}
}

std::vector <Tile*>  World::getInBox(int minX, int minY, int maxX, int maxY)
{

	std::vector<Tile*>  output((maxX - minX + 1) * (maxY - minY + 1), nullptr);

	int tracker = 0;
	for(int x = 0; x < (maxX-minX+1) ; x++ )
	{
		for(int y = 0; y < (maxY-minY+1) ; y++ )
		{
			output[tracker] = &map[x+minX - 1][y+minY - 1];
			tracker++;
		}
	}
	return output;

}


std::vector <Tile*> World::getInView(Tile& center, int range)
{
	int minX =  center.getX();
	int maxX = minX;
	int minY = center.getY();
	int maxY = minY;
	changeCoordinates(minX, -range, minY, -range);
	changeCoordinates(maxX,  range, maxY,  range);

	std::vector <Tile*> output = getInBox(minX, minY, maxX, maxY);
	return output;

}


/**This recursive method finds a diamond of a certain size. It starts from the middle and looks from all sides.
 * Null direction is the direction(s) not to check. This prevents the method from backtracking, (so let's say we stepped north,
 * now we don't ever want to step back south, in any of these future steps).
 *
 */
std::vector<Tile*> World::getInDiamond(Tile& mid, int range, int nullDirection )
{

	std::cout << "\nDiamond Tile: " << mid.getX() << "," << mid.getY() << " Range: "  << range << " Null direction(s)" << nullDirection;
	std::vector<Tile*> output;
	output.insert(output.end(),&mid);
	if(range == 0)
	{
		return output;
	}
	if( (nullDirection & NORTH) == 0)
	{
		std::vector<Tile*> add = getInDiamond(*getStep(mid, NORTH), range - 1, nullDirection | SOUTH);
		output.insert(output.end(),add.begin(), add.end());
	}
	if( (nullDirection & EAST) == 0)
	{
		std::vector<Tile*> add = getInDiamond(*getStep(mid, EAST), range - 1, nullDirection | WEST);
		output.insert(output.end(),add.begin(), add.end());
	}
	if( (nullDirection & SOUTH) == 0)
	{
		std::vector<Tile*> add = getInDiamond(*getStep(mid, SOUTH), range - 1, nullDirection | NORTH);
		output.insert(output.end(),add.begin(), add.end());
	}
	if( (nullDirection & WEST) == 0)
	{
		std::vector<Tile*> add = getInDiamond(*getStep(mid, WEST), range - 1, nullDirection | EAST);
		output.insert(output.end(),add.begin(), add.end());
	}
	return output;
}

/**Works the same as inDiamond, except now it decreases the range in each step by the tiles movement cost value.
 *It also ignores tiles that are not passableget
 */
std::vector<Tile*> World::getInMoveRange(Tile& mid, int range, int nullDirection )
{
	std::vector<Tile*> output;
															//Make sure the tile is passable if not, return.
	if(mid.getPassable() == false && nullDirection != 0)	//Null direction is only equal to zero on the first run, so this makes sure a player can move if they are on a unpassable tile.
	{
		return output;		//currently empty
	}

	int newRange = range;
	if(nullDirection != 0)//If not the first tile, change the range.
	{
		newRange -= mid.getMovementCost();
	}
	if(newRange < 0 )
	{
		return output;	//currently empty
	}

	output.insert(output.end(),&mid);
	if(newRange == 0)
	{
		return output;
	}
	if( (nullDirection & NORTH) == 0)
	{
		std::vector<Tile*> add = getInMoveRange(*getStep(mid, NORTH), newRange, nullDirection | SOUTH);
		output.insert(output.end(),add.begin(), add.end());
	}
	if( (nullDirection & EAST) == 0)
	{
		std::vector<Tile*> add = getInMoveRange(*getStep(mid, EAST),  newRange, nullDirection | WEST);
		output.insert(output.end(),add.begin(), add.end());
	}
	if( (nullDirection & SOUTH) == 0)
	{
		std::vector<Tile*> add = getInMoveRange(*getStep(mid, SOUTH), newRange, nullDirection | NORTH);
		output.insert(output.end(),add.begin(), add.end());
	}
	if( (nullDirection & WEST) == 0)
	{
		std::vector<Tile*> add = getInMoveRange(*getStep(mid, WEST),  newRange, nullDirection | EAST);
		output.insert(output.end(),add.begin(), add.end());
	}
	return output;
}

std::vector<Tile*> World::getInRow(int row)	//y is row
{
	std::vector<Tile*> output;
	for (int x = 0 ; x< maxX ; x++)
	{
		output.insert(output.end(), &map[x][row -1]);
	}
	return output;
}

std::vector<Tile*> World::getInColumn(int column)//x is column
{
	std::vector<Tile*> output;
	for(int y = 0 ; y < maxY ; y++)
	{
		output.insert(output.end(), &map[column -1][y]);
	}
	return output;
}

/*Finds all the tiles in a line from a starting point
 *
 */
std::vector<Tile*> World::getInLine(Tile& start, int length, int direction)
{
	std::vector<Tile*> output;
	output.insert(output.end(), &start);
	if(length <= 0)
	{
		return output;
	}
	std::vector<Tile*> add = getInLine(*getStep(start, direction), length - 1, direction);
	output.insert(output.end(), add.begin(), add.end());
	return output;
}

/**Uses the getInLine function and just finds the line for each cardinal direction and adds it to the output.
 *
 */
std::vector<Tile*> World::getInCross(Tile& start, int length)
{
	std::vector<Tile*> output;
	std::vector<Tile*> line;

	line = getInLine(start, length, NORTH);
	output.insert(output.end(), line.begin(), line.end());

	line = getInLine(start, length, EAST);
	output.insert(output.end(), line.begin(), line.end());

	line = getInLine(start, length, SOUTH);
	output.insert(output.end(), line.begin(), line.end());

	line = getInLine(start, length, WEST);
	output.insert(output.end(), line.begin(), line.end());

	return output;
}
