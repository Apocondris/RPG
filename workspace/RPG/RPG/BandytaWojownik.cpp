#include "BandytaWojownik.h"



BandytaWojownik::BandytaWojownik()
{
	this->nazwa = "Bandyta Wojownik";
	//musi jakosc dziedziczyc po postaci i miec manewr szarza, statystyki jak poczatkujacy wojownik
	zdrowie = 100;
	klasa_pancerza = 1;
	szybkosc = 3;
	szczescie = 1;
	atak = 30;
	obrona = 30;
	zasieg = 1;
	obrazenia = 10;
	max_zdrowie = 100;
	wartosc = (max_zdrowie + obrazenia + obrona + atak) / 10;
}


BandytaWojownik::~BandytaWojownik()
{
}

string BandytaWojownik::losuj_lup()
{
	int wylosowano = rand() % 6;
	switch (wylosowano)
	{
	case 0: return "Brak lupu";
	case 1: return "lup1";
	case 2: return "lup2";
	case 3: return "lup3";
	case 4: return "lup4";
	case 5: return "lup5";
	}

}