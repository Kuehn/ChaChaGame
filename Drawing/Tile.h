/*
 * Tile.h
 *
 *  Created on: Nov 6, 2014
 *      Author: Josh
 */

#ifndef TILE_H_
#define TILE_H_
//#include "Character.h"
#include "GameObject.h"

class Tile : public GameObject //Inherits from GameObject class..right now I think thats best, but may need to change later after we talk
{
	int red, green, blue;
	int x, y;
	int size; //Size of tile, could be float but for not int.
	bool passable, opacity;
	int movementCost;
	//Character content;	//TODO figure out this shit
	char image;	//change to file name later
	int rendX, rendY;



	public: //Switched to protected, I believe they should be.
	 Tile();
	 Tile(int,int,int,int,int);// x and y coordinates
	 virtual ~Tile();
	 //getters and setters
//	 Character getContent();
//	 void setContent(Character inChar);
	 void render();
	 void setRendXLoc(int);
	 void setRendYLoc(int);
	 void setRGB(int, int, int);
	 
	 int getRendX();
	 int getRendY();

	 int getSize();
	 int getX();
	 int getY();
	 int getMovementCost();
	 bool getPassable();
	 char getImage();	//change to file
	 void setImage(char);
	 void setSize(int);
	 void setX(int);	//It makes me slightlly nervous that these are public.
	 void setY(int);
	 void setMovementCost(int);
	 void setPassable(bool);
	 //TODO more getters and setters
};

#endif /* TILE_H_ */
