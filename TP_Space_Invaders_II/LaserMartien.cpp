#include "LaserMartien.h"

#include <iostream>
using namespace std;
void LaserMartien::moveLaser()
{

	removeLaser();
	if (coord.getPositionY()<39)
	{
		coord.setPositionY(coord.getPositionY() + 1);
		putLaser();
	}
	else
		isAlive = false;

}
void LaserMartien::putLaser() 
{
	coord.gotoXY(coord.getPositionX(), coord.getPositionY());
	cout << char(221);
}
void LaserMartien::startLaser(int x, int y) 
{

	coord.setPositionX(x);
	coord.setPositionY(y);
	putLaser();
	isAlive = true;
}
void LaserMartien::initLaser() {
	isAlive = false;
}