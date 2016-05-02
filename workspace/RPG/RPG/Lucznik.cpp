#include "Lucznik.h"



Lucznik::Lucznik()
{
}

Lucznik::Lucznik(string imie) : Postac(imie,"lucznik")
{
	this->imie = imie;
	zdrowie=80;
	punktyDoWydania=6;
	klasa_pancerza=0;
	szybkosc=3;
	szczescie=2;
	atak=40;
	obrona=20;
	wytrzymalosc=10;
	zasieg=10;
	obrazenia=10;
	max_zdrowie=80;
	max_wytrzymalosc=10;
	strzaly = 10;
}


Lucznik::~Lucznik()
{
}
