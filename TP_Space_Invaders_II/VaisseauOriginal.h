#pragma once
#include"Vaisseau.h"
#include "Laser.h"
#include"timer.h"

#define MAX_LASERS 8

class VaisseauOriginal :public Vaisseau {
public:
	int nbLasers;
	Laser laserPrincipal[MAX_LASERS];
	Laser laserSecondaire[MAX_LASERS];
	Laser laserSecondaire2[MAX_LASERS];
	Timer timerVaisseau;
	Timer timerLaser;
	VaisseauOriginal();

	void removeVaisseau() const;
	void putVaisseau() const;
	void modifierPositionY(char key);
	void init();
	void tirer();
	void starLaser(int i);
	void starLaser2(int i);
	void starLaser3(int i);
};