#pragma once
#include "VaisseauOriginal.h"
#include"timer.h" 
#include "Laser.h"
#include"Martien.h"
#include"ExtraTerrestre.h"
#include "UIKit.h"
#include"LaserMartien.h"
#include"MartienSoldat.h"
#include"Monstres.h"

#define MAX_ENNEMI 16
#define MAX_LASERS 8
#define LARGUEUR 100
#define LONGUEUR 43

class jeu {
public:
	VaisseauOriginal monVaisseau;
	Timer timeApparaitionMartien;
	Timer timebougerMartien;
	Monstres** vilain; 

	jeu();
	void initialisation();
	void jouer(bool &finDeJeu);
	static void clrscr();
};