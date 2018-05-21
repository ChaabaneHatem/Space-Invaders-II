#include"fonctSpace.h"
#include"jeu.h"
#define MAX_ENNEMI 16
#define MAX_LASERS 8
#define LARGUEUR 100
#define LONGUEUR 43
void reglage() {
	//initialisation des nombres pseudo-aleatoire
	srand((unsigned int)time(NULL));
	//les cadres et autres fonctionalité
	UIKit::curseurVisible(false);
	UIKit::cadre(0, 0, LARGUEUR, LONGUEUR, FOREGROUND_BLUE);
	UIKit::color(0x000F);
	UIKit::cadre(101, 12, 119, 43, FOREGROUND_RED);
	UIKit::color(0x000F);
	
	UIKit::gotoXY(105, 15);
	cout << "score : " << 0;
	UIKit::gotoXY(105, 18);
	cout << "nb Vie : " << 3;
	UIKit::gotoXY(105, 21);
	cout << "nb Ennemi : " << 0;
	
	UIKit::gotoXY(60, 15);
	cout << char(2);
	UIKit::gotoXY(40, 15);
	cout << char(2);
}