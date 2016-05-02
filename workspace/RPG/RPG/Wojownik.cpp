#include "Wojownik.h"



Wojownik::Wojownik()
{
}

Wojownik::Wojownik(string imie) : Postac(imie,"wojownik")
{
	this->imie = imie;
	 zdrowie=100;
	 punktyDoWydania=6;
	 klasa_pancerza=1;
	 szybkosc=3;
	 szczescie=1;
	 atak=30;
	 obrona=30;
	 wytrzymalosc=15;
	 zasieg=1;
	 obrazenia=10;
	 max_zdrowie=100;
	 max_wytrzymalosc=100;

}


Wojownik::~Wojownik()
{
}
