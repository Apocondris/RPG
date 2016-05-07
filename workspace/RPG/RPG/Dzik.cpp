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
	int wylosowano = rand() % 8;
	switch (wylosowano)
	{
	case 0: return "Brak ³upu";
	case 1: return "Skóra dzika";
	case 2: return "K³y dzika";
	case 3: return "Miêso dzika";
	case 4: return "Trofeum z dzika";
	case 5: return "Miecz Dziczy Kie³"; 
	case 6: return "£uk Dziczej Wœciek³oœci";
	case 7: return "Pancerz z dziczych skór";

	}

}