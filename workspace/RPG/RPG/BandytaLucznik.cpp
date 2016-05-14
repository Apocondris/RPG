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
	doswiadczenie = 20;
}


BandytaLucznik::~BandytaLucznik()
{
}

string BandytaLucznik::losuj_lup()
{
	int wylosowano = rand() % 2;
	switch (wylosowano)
	{
	case 0: return "Brak lupu";
	case 1: return "Zloty zab";
	}

}