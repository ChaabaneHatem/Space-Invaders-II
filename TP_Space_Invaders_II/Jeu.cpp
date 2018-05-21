#include"jeu.h"


jeu::jeu() :timeApparaitionMartien(4000), timebougerMartien(1000) {
	this->vilain = new Monstres*[MAX_ENNEMI];
}
void jeu::initialisation() {
	monVaisseau.init();
}
void jeu::jouer(bool &finDeJeu) {
	int nbEnnemi = ExtraTerrestre::getNombreExtraTerrestre();
	monVaisseau.tirer();
	// augmenter nombre de laser de vaisseau 
	for (int i = 0; i < MAX_LASERS; i++)
	{
		if (monVaisseau.laserPrincipal[i].isAlive) {
			if (monVaisseau.laserPrincipal[i].coord.getPositionX() == 60 && monVaisseau.laserPrincipal[i].coord.getPositionY() == 15) {
				monVaisseau.nbLasers += 1;
			}
			if (monVaisseau.laserPrincipal[i].coord.getPositionX() == 40 && monVaisseau.laserPrincipal[i].coord.getPositionY() == 15)
				monVaisseau.nbLasers = 1;
		}

	}
	for (int i = 0; i < MAX_ENNEMI; i++)
	{
		if (timeApparaitionMartien.estPret()) {
			vilain[nbEnnemi] = new MartienSoldat;
			vilain[nbEnnemi]->creer();

		}
		if (timebougerMartien.estPret())
			for (int i = 0; i < nbEnnemi; i++)
				vilain[i]->bouger();

		for (int i = 0; i < nbEnnemi; i++) {
			if (vilain[i]->isAlive)
				vilain[i]->tirer();
			Monstres::collision(*(vilain[i]), monVaisseau);
			vilain[i]->collisionLaser(monVaisseau);
			//si un ennemi est mort on le deplace dans le dernier case de tableau
			/*if (vilain[i]->isAlive == false) {
				nbEnnemi++;
				vilain[i] = vilain[nbEnnemi];
				nbEnnemi--;
			}*/
		}
	}
	for (int i = 0; i < nbEnnemi; i++)
	{
		vilain[i]->finDeJeu(monVaisseau, finDeJeu);
	}
}
void jeu::clrscr()
{
	system("@cls||clear");
}