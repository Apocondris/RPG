#pragma once

#include "WszystkieKlasy.h"
#include "Przeciwnik.h"

class BandytaWojownik : public Przeciwnik
{
public:
	BandytaWojownik();
	~BandytaWojownik();
	string losuj_lup();
};

