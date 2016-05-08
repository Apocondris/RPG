#include "Wilk.h"
#include "Przeciwnik.h"
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;


Wilk::Wilk()
{
	this->nazwa = "Wilk";
	zdrowie = 60;
	klasa_pancerza = 0;
	szybkosc = 6;
	szczescie = 10;
	atak = 60;
	obrona = 10;
	zasieg = 1;
	obrazenia = 20;
	max_zdrowie = 60;
	wartosc = (max_zdrowie + obrazenia + obrona + atak) / 10;
}


Wilk::~Wilk()
{
}

string Wilk :: losuj_lup()
{
	int wylosowano = rand() % 2;
	switch (wylosowano)
	{
		case 0: return "Brak lupu";
		case 1: return "Skora wilka";
	}

}
