#include "Niedzwiedz.h"



Niedzwiedz::Niedzwiedz()
{
	this->nazwa = "Niedzwiedz";
	zdrowie = 140;
	klasa_pancerza = 5;
	szybkosc = 2;
	szczescie = 1;
	atak = 30;
	obrona = 50;
	zasieg = 1;
	obrazenia = 15;
	max_zdrowie = 140;
}


Niedzwiedz::~Niedzwiedz()
{
}

string Niedzwiedz::losuj_lup()
{
	int wylosowano = rand() % 9;
	switch (wylosowano)
	{
	case 0: return "Brak ³upu";
	case 1: return "Skóra niedzwiedzia";
	case 2: return "Niedzwiedzie kly";
	case 3: return "Pazury niedzwiedzia";
	case 4: return "Trofeum z niedzwiedzia";
	case 5: return "Zbroja Serce Dziczy";
	case 6: return "Buty nieulêknionego";
	case 7: return "Miecz niedzwiedziej furii";
	case 8: return "Pancerz wytrzymalosci";

	}

}