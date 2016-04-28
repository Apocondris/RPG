#pragma once

#include "WszystkieKlasy.h"
#include "Lokalizacja.h"

class Miasto : public Lokalizacja
{
public:
	Miasto(Postac*);
	Miasto(Postac*, Lokalizacja*);

	void start(void);

private:
	Kupiec * kupiec;
	static const int iloscNazwMiast = 5;
	static string nazwyMiast[iloscNazwMiast];

	void menuGlowne(bool &);

	void logo();
};

