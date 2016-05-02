#pragma once

#include "WszystkieKlasy.h"
#include "Przeciwnik.h"

class Dzik : public Przeciwnik
{
public:
	Dzik();
	~Dzik();
	string losuj_lup();
};

