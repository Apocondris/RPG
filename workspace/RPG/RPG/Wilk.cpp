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
}


Wilk::~Wilk()
{
}

string Wilk :: losuj_lup()
{
	int wylosowano = rand() % 8;
	switch (wylosowano)
	{
		case 0: return "Brak �upu";
		case 1: return "Sk�ra wilka";
		case 2: return "Z�by wilka";
		case 3: return "Pazury wilka";
		case 4: return "Trofeum z wilka";
		case 5: return "Buty wilczych sus�w";
		case 6: return "Buty psiego szcz�cia";
		case 7: return "�uk psiego trafu";
	}

}
