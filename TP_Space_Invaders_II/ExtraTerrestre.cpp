#include "ExtraTerrestre.h"
#include <stdlib.h>
#include<iostream>
using namespace std;

int ExtraTerrestre::nombreExtraTerrestre = 0;

ExtraTerrestre::ExtraTerrestre(int type,int valeur)
{
	typeExtraTerrestre=type;
	valeurExtraTerrestre=valeur;
}

void ExtraTerrestre::reduireNombreExtraTerrestre()
{
	nombreExtraTerrestre--;
}

int ExtraTerrestre::getNombreExtraTerrestre()
{
	return nombreExtraTerrestre;
}

void ExtraTerrestre::resetNombreExtraTerrestre()
{
	nombreExtraTerrestre=0;
}

void ExtraTerrestre::removeExtraTerrestre() const
{
	coord.gotoXY(coord.getPositionX(),coord.getPositionY());
	cout << " ";	
}

void ExtraTerrestre::putExtraTerrestre() const
{
	coord.gotoXY(coord.getPositionX(),coord.getPositionY());
	cout << char(typeExtraTerrestre);
}

int ExtraTerrestre::ajouterPoints() const
{
	return valeurExtraTerrestre;
}

void ExtraTerrestre::resetExtraTerrestre()
{
	coord.setPositionX(3+rand()%90);
	coord.setPositionY(1+rand()%20);
	isAlive = true;
	nombreExtraTerrestre++;
}

