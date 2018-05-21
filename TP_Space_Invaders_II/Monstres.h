#pragma once
#include"ExtraTerrestre.h"
#include"VaisseauOriginal.h"


class Monstres :public ExtraTerrestre {
public:
	Monstres();
	virtual void creer() = 0;
	virtual void bouger() = 0;
	virtual void tirer() = 0;
	virtual void removeExtraTerrestre() = 0;
	static void collision(Monstres & Ennemi, VaisseauOriginal & unVaisseau);
	virtual void collisionLaser(VaisseauOriginal & unVaisseau) = 0;
	virtual void finDeJeu(const VaisseauOriginal & unVaisseau, bool & findeJeu) = 0;
};