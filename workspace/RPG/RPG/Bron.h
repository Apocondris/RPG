#pragma once

#include "WszystkieKlasy.h"
#include "Przedmiot.h"

class Bron : public Przedmiot
{
public:
	Bron(string nazwa, int zasieg);
	Bron(string nazwa, int szybkosc, int szczescie, int atak, int zasieg, int obrazenia);

	int szczescie;
	int szybkosc;
	int atak;
	int zasieg;
	int obrazenia;

	string toString(void);
};

