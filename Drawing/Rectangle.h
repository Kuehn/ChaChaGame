#pragma once
class Rectangle
{
public:
	Rectangle(int, int, int, int);
	~Rectangle();
	int getX();
	int getY();
	int getArea();
	int getWidth();
	int getHeight();
	bool intersects(Rectangle);
private:
	int x;
	int y;
	int width;
	int height;
};

