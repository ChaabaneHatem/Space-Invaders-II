#pragma once
#include"Monstres.h"
#include"LaserMartien.h"
#include"timer.h"

class MartienSoldat :public Monstres {
public:
	LaserMartien unLaser;
	Timer timeLaser;
	Timer timeApparaitionMartien;
	bool jiggle;

	MartienSoldat();
	void removeExtraTerrestre();
	void putExtraTerrestre();
	void putExtraTerrestre1();
	void creer();
	void bouger()  ;
	void tirer();
	void collisionLaser(VaisseauOriginal & unVaisseau);
	void finDeJeu(const VaisseauOriginal & unVaisseau, bool & findeJeu);



};