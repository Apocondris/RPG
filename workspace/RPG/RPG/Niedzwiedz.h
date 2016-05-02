#pragma once

#include "WszystkieKlasy.h"
#include "Przeciwnik.h"

class Niedzwiedz : public Przeciwnik
{
public:
	Niedzwiedz();
	~Niedzwiedz();
	string losuj_lup();
};

