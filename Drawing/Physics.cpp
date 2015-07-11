#include "Physics.h"


Physics::Physics()
{
}


Physics::~Physics()
{
}

bool Physics::checkCollision(GameObject go1, GameObject go2)
{
	Rectangle r1 ((int)go1.getSizeX(), (int)go1.getSizeX(), (int)go1.getY(), (int)go1.getSizeY());
	Rectangle r2((int)go2.getSizeX(), (int)go2.getSizeX(), (int)go2.getY(), (int)go2.getSizeY());
	return r1.intersects(r2);
	//return false;
}
