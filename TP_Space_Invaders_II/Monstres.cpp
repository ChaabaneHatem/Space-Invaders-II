#include"Monstres.h"

Monstres::Monstres():ExtraTerrestre(1, 20) {

}


void Monstres::bouger() {

}
void Monstres::tirer() {

}

void Monstres::collision(Monstres & Ennemi, VaisseauOriginal & unVaisseau) {
	for (int i = 0; i < MAX_LASERS; i++)
	{
		for (int i = 0; i < 4; i++)
		{
			if (Ennemi.coord.getPositionX()+i == unVaisseau.laserPrincipal[i].coord.getPositionX()
				&& Ennemi.coord.getPositionY() == unVaisseau.laserPrincipal[i].coord.getPositionY()) {
				unVaisseau.laserPrincipal[i].killLaser();
				Ennemi.removeExtraTerrestre();
				Ennemi.coord.setPositionX(110);
				Ennemi.coord.setPositionY(2);
				Ennemi.reduireNombreExtraTerrestre();
				Ennemi.isAlive = false;
			}
		}
		
	}
}
