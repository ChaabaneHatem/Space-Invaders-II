#include"VaisseauOriginal.h"
#include"UIKit.h"
#include <iostream>
#include <Windows.h>
using namespace std;

void VaisseauOriginal::removeVaisseau() const {
	coord.gotoXY(coord.getPositionX(), coord.getPositionY());
	cout << "           " << endl;
	coord.gotoXY(coord.getPositionX(), coord.getPositionY() + 1);
	cout << "            " << endl;
	coord.gotoXY(coord.getPositionX() - 1, coord.getPositionY() + 2);
	cout << "             " << endl;
	coord.gotoXY(coord.getPositionX() - 1, coord.getPositionY() + 3);
	cout << "             " << endl;
}
void VaisseauOriginal::putVaisseau() const {
	UIKit::color(FOREGROUND_GREEN);
	coord.gotoXY(coord.getPositionX(), coord.getPositionY());
	cout << "     " << char(220) << "     " << endl;
	coord.gotoXY(coord.getPositionX(), coord.getPositionY() + 1);
	cout << " " << char(220) << "  " << char(219) << char(219) << char(219) << "  " << char(220) << " " << endl;
	coord.gotoXY(coord.getPositionX(), coord.getPositionY() + 2);
	cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << endl;
	coord.gotoXY(coord.getPositionX(), coord.getPositionY() + 3);
	cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << endl;
	UIKit::color(0x000f);
}

VaisseauOriginal::VaisseauOriginal() :timerVaisseau(10), timerLaser(50) {
	nbLasers = 0;
	putVaisseau();
};
void VaisseauOriginal::modifierPositionY(char key) {
	removeVaisseau();
	switch (key)
	{
	case 'o':	coord.setPositionY(coord.getPositionY() - 1);	break;
	case 'm':	coord.setPositionY(coord.getPositionY() + 1);
	}
	putVaisseau();
}

void VaisseauOriginal::tirer() {
	UIKit::color(FOREGROUND_RED);
	//	gestion du clavier
	if (_kbhit() && timerVaisseau.estPret()) {
		char touche = _getch();

		if (touche == ' ') {
			//	on recherche un laser libre
			int i = 0;
			if (nbLasers >= 2) {
				while (i < MAX_LASERS && laserSecondaire2[i].isAlive)
					i++;

				if (i < MAX_LASERS) {
					starLaser2(i);
				}
			}
			if (nbLasers >= 1) {
				while (i < MAX_LASERS && laserSecondaire[i].isAlive)
					i++;

				if (i < MAX_LASERS) {
					starLaser3(i);
				}
			}
			while (i < MAX_LASERS && laserPrincipal[i].isAlive)
				i++;

			if (i < MAX_LASERS) {
				starLaser(i);
			}
		}
		else {
			modifierPosition(touche);
			modifierPositionY(touche);
		}
	}

	//	on déplace le laser
	if (timerLaser.estPret()) {
		for (int i = 0; i < MAX_LASERS; i++)
			if (laserPrincipal[i].isAlive)
				laserPrincipal[i].moveLaser();
		for (int i = 0; i < MAX_LASERS; i++)
			if (laserSecondaire[i].isAlive)
				laserSecondaire[i].moveLaser();
		for (int i = 0; i < MAX_LASERS; i++)
			if (laserSecondaire2[i].isAlive)
				laserSecondaire2[i].moveLaser();
	}
	
}
void VaisseauOriginal::init() {
	//	un laser (pas à l'écran au début)
	for (int i = 0; i < MAX_LASERS; i++)
		laserPrincipal[i].isAlive = false;
	for (int i = 0; i < MAX_LASERS; i++)
		laserSecondaire[i].isAlive = false;
}

void  VaisseauOriginal::starLaser(int i) {
	laserPrincipal[i].coord.setPositionX(coord.getPositionX() + 5);
	laserPrincipal[i].coord.setPositionY(coord.getPositionY() - 1);
	//generer un beep (son)
	//Beep(1000, 40);
	laserPrincipal[i].putLaser();
	laserPrincipal[i].isAlive = true;
}

void VaisseauOriginal::starLaser2(int i) {
	laserSecondaire2[i].coord.setPositionX(coord.getPositionX() + 1);
	laserSecondaire2[i].coord.setPositionY(coord.getPositionY());
	laserSecondaire2[i].putLaser();
	laserSecondaire2[i].isAlive = true;
}

void VaisseauOriginal::starLaser3(int i) {
	laserSecondaire[i].coord.setPositionX(coord.getPositionX() + 9);
	laserSecondaire[i].coord.setPositionY(coord.getPositionY() );
	laserSecondaire[i].putLaser();
	laserSecondaire[i].isAlive = true;
}