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
}


Utopiec::~Utopiec()
{
}

string Utopiec::losuj_lup()
{
	int wylosowano = rand() % 6;
	switch (wylosowano)
	{
	case 0: return "Brak ³upu";
	case 1: return "Skóra topielca";
	case 2: return "Trucizna topielca";
	case 3: return "Pazury topielca";
	case 4: return "Trofeum z topielca";
	case 5: return "Miecz krawêdzi œwiata";

	}

}