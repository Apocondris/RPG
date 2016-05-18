#include "Lucznik.h"
#include "Bron.h"
#include "FabrykaWyposazenia.h"



Lucznik::Lucznik()
{
}

Lucznik::Lucznik(string imie) : Postac(imie, "lucznik", FabrykaWyposazenia::stworzLuk())
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
	zasieg=1;
	obrazenia=1;
	max_zdrowie=80;
	max_wytrzymalosc=10;
	strzaly = 20;

	posiadaneZloto = 200;
}
