#pragma once
#include "Laser.h"

class LaserMartien: public Laser
{
public:
	void startLaser(int x,int y);

	void moveLaser();
	void putLaser();
	void initLaser();

};