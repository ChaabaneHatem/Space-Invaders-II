//#include "VaisseauOriginal.h"
//#include"timer.h" 
//#include "Laser.h"
//#include"Martien.h"
//#include"ExtraTerrestre.h"
//#include "UIKit.h"
//#include"LaserMartien.h"
//#include"MartienSoldat.h"
//#include"Monstres.h"
#include"jeu.h"
#include"fonctSpace.h"
#include <stdlib.h>


#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>

#define MAX_ENNEMI 16
#define MAX_LASERS 8
#define LARGUEUR 100
#define LONGUEUR 43
int main()
{
	reglage();
	bool finDeJeu = false;
	jeu unjeu;
	unjeu.initialisation();
	//	boucle principale de jeu
	while (!finDeJeu) {
		
		unjeu.jouer(finDeJeu);

	}
	if (finDeJeu) {
		jeu::clrscr();
		UIKit::gotoXY(50, 20);
		cout << "GAME OVER !!";
		UIKit::gotoXY(0, 0);
	}
		
	return 0;
}