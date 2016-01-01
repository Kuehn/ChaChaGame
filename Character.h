/*
 * Character.h
 *
 *  Created on: Nov 8, 2014
 *      Author: Josh
 */

#ifndef CHARACTER_H_
#define CHARACTER_H_


class Character
{
int x, y, movement;
char image; // become a file name in future

public:
	Character(int,int);
	virtual ~Character();
};

#endif /* CHARACTER_H_ */
