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
	case 0: return "Brak �upu";
	case 1: return "Sk�ra dzika";
	case 2: return "K�y dzika";
	case 3: return "Mi�so dzika";
	case 4: return "Trofeum z dzika";
	case 5: return "Miecz Dziczy Kie�"; 
	case 6: return "�uk Dziczej W�ciek�o�ci";
	case 7: return "Pancerz z dziczych sk�r";

	}

}