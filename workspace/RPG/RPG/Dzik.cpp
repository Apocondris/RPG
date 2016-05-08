#include "Dzik.h"



Dzik::Dzik()
{
	this->nazwa = "Dzik";
	zdrowie = 120;
	klasa_pancerza =3;
	szybkosc = 2;
	szczescie = 5;
	atak = 20;
	obrona = 50;
	zasieg = 1;
	obrazenia = 14;
	max_zdrowie = 120;
	wartosc = (max_zdrowie + obrazenia + obrona + atak) / 10;
}


Dzik::~Dzik()
{
}
string Dzik::losuj_lup()
{
	int wylosowano = rand() % 2;
	switch (wylosowano)
	{
	case 0: return "Brak lupu";
	case 1: return "Skora dzika";

	}

}