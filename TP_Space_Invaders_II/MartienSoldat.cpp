#include"MartienSoldat.h"
#include"UIKit.h"
#include<iostream>
using namespace std;

MartienSoldat::MartienSoldat() :timeLaser(100), timeApparaitionMartien(2000) {
	jiggle = true;
	unLaser.isAlive = false;
}
void MartienSoldat::putExtraTerrestre() {

	coord.gotoXY(coord.getPositionX(), coord.getPositionY());
	cout << "{@@}" << endl;
	coord.gotoXY(coord.getPositionX(), coord.getPositionY()+1);
	cout << " \\/" << endl;
}
void MartienSoldat::putExtraTerrestre1() {

	coord.gotoXY(coord.getPositionX(), coord.getPositionY());
	cout << "{@@}" << endl;
	coord.gotoXY(coord.getPositionX(), coord.getPositionY() + 1);
	cout << "/\"\"\\" << endl;
}
void MartienSoldat::removeExtraTerrestre() {
	coord.gotoXY(coord.getPositionX(), coord.getPositionY());
	cout << "    " << endl;
	coord.gotoXY(coord.getPositionX(), coord.getPositionY() + 1);
	cout << "    " << endl;
}
void MartienSoldat::bouger() {
	removeExtraTerrestre();

	if (jiggle) {
		coord.setPositionX(coord.getPositionX() - 3);
		UIKit::gotoXY(coord.getPositionX() + 2, coord.getPositionY() + 1);
		coord.setPositionX(coord.getPositionX() - 3);
		putExtraTerrestre();
	}
	else {
		coord.setPositionX(coord.getPositionX() + 3);
		UIKit::gotoXY(coord.getPositionX() - 2, coord.getPositionY() + 1);
		coord.setPositionX(coord.getPositionX() + 3);
		putExtraTerrestre1();
	}

	jiggle = !jiggle;

	
}
void MartienSoldat::creer() {
	//if (timeApparaitionMartien.estPret()) {
		this->resetExtraTerrestre();
		this->putExtraTerrestre();
	//}
}
void MartienSoldat::tirer() {
	if ( !unLaser.isAlive & timeApparaitionMartien.estPret()) {
		unLaser.startLaser(this->coord.getPositionX()+2, this->coord.getPositionY()+2);
		timeLaser.start();
	}
	if (unLaser.isAlive && timeLaser.estPret())
		unLaser.moveLaser();
}
void MartienSoldat::collisionLaser(VaisseauOriginal & unVaisseau) {
	for (int i = 0; i < MAX_LASERS; i++)
	{
		if (unLaser.coord.getPositionX() == unVaisseau.laserPrincipal[i].coord.getPositionX()
			&& unLaser.coord.getPositionY() == unVaisseau.laserPrincipal[i].coord.getPositionY()) {
			unVaisseau.laserPrincipal[i].killLaser();
			unLaser.isAlive = false;
			unLaser.coord.setPositionX(110);
			unLaser.coord.setPositionY(2);
			unVaisseau.laserPrincipal[i].coord.setPositionX(110);
			unVaisseau.laserPrincipal[i].coord.setPositionY(2);
		}

	}
}
void MartienSoldat::finDeJeu(const VaisseauOriginal & unVaisseau, bool & findeJeu) {
	for (int i = 0; i < 11; i++)
	{
		if (unLaser.coord.getPositionX() == unVaisseau.coord.getPositionX() + i &&
			unLaser.coord.getPositionY() == unVaisseau.coord.getPositionY())
			findeJeu = true;
		
	}
	
}