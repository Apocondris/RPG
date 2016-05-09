#include "Bron.h"
#include <time.h>


Bron::Bron(string nazwa)
{
	srand(time(NULL));
	this->nazwa = nazwa;
	this->szczescie = szczescie;
	this->szybkosc = szybkosc;
	this->atak = atak;
	this->zasieg = zasieg;
	this->obrazenia = obrazenia;
	this->wartosc = (obrazenia + szczescie + atak + szybkosc) * 10;
}

Bron::Bron(string nazwa, int szybkosc, int szczescie, int atak, int zasieg, int obrazenia)
{
	this->nazwa = nazwa;
	this->szczescie = szczescie;
	this->szybkosc = szybkosc;
	this->atak = atak;
	this->zasieg = zasieg;
	this->obrazenia = obrazenia;
	this->wartosc = (obrazenia + szczescie + atak + szybkosc) * 10;
}
