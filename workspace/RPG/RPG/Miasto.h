#pragma once

#include "WszystkieKlasy.h"
#include "Lokalizacja.h"
#include "Kupiec.h"

class Miasto : public Lokalizacja
{
public:
	Miasto(shared_ptr<Postac>);
	Miasto(shared_ptr<Postac>, shared_ptr<Lokalizacja>);

	void start(void);

private:
	unique_ptr<Kupiec> kupiec;
	static const int iloscNazwMiast = 5;
	static string nazwyMiast[iloscNazwMiast];

	void menuGlowne(bool &);

	void logo();
};

