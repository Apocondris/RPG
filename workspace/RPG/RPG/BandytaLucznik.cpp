#include "BandytaLucznik.h"



BandytaLucznik::BandytaLucznik()
{
	this->nazwa = "Bandyta Lucznik";
	//musi miec manewr strzal i odskok i statystyki jak poczatkujacy lucznik - dziedziczenie po postaci
	zdrowie = 80;
	klasa_pancerza = 0;
	szybkosc = 3;
	szczescie = 2;
	atak = 40;
	obrona = 20;
	zasieg = 10;
	obrazenia = 10;
	max_zdrowie = 80;
	wartosc = (max_zdrowie + obrazenia + obrona + atak) / 10;
}


BandytaLucznik::~BandytaLucznik()
{
}

string BandytaLucznik::losuj_lup()
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