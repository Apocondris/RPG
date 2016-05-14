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
	wartosc = (max_zdrowie + obrazenia + obrona + atak) / 10;
	doswiadczenie = 40;
}


Niedzwiedz::~Niedzwiedz()
{
}

string Niedzwiedz::losuj_lup()
{
	int wylosowano = rand() % 2;
	switch (wylosowano)
	{
	case 0: return "Brak lupu";
	case 1: return "Skora niedzwiedzia";

	}

}