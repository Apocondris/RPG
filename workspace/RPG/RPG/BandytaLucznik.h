#pragma once

#include "WszystkieKlasy.h"
#include "Przeciwnik.h"

class BandytaLucznik : public Przeciwnik
{
public:
	BandytaLucznik();
	~BandytaLucznik();
	string losuj_lup();
};

