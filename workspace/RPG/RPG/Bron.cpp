#include "Bron.h"
#include <time.h>
#include "Przedmiot.h"


Bron::Bron(string nazwa, int zasieg)
{
	
	this->nazwa = nazwa;
	this->szczescie = 0;
	this->szybkosc = 0;
	this->atak = 0;
	this->zasieg = zasieg;
	this->obrazenia = 10;
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

string Bron::toString(void)
{
	string str = "Bron: ";
	str += nazwa + "	";
	str += "atak: " + to_string(atak) + "	";
	str += "obrazenia: " + to_string(obrazenia) + "	";
	str += "szybkosc: " + to_string(szybkosc) + "	";
	str += "szczescie: " + to_string(szczescie) + "	";
	str += "zasieg: " + to_string(zasieg);
	return str;
}
