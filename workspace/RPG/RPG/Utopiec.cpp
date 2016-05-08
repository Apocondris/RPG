#include "Utopiec.h"



Utopiec::Utopiec()
{
	this->nazwa = "Utopiec";
	zdrowie = 100;
	klasa_pancerza = 1;
	szybkosc = 1;
	szczescie = 10;
	atak = 60;
	obrona = 40;
	zasieg = 1;
	obrazenia = 25;
	max_zdrowie = 100;
	wartosc = (max_zdrowie + obrazenia + obrona + atak) / 10;
}


Utopiec::~Utopiec()
{
}

string Utopiec::losuj_lup()
{
	int wylosowano = rand() % 2;
	switch (wylosowano)
	{
	case 0: return "Brak lupu";
	case 1: return "Skora utopca";
	}

}