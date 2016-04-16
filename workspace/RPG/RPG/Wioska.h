#pragma once

#include "Lokalizacja.h"

class Wioska : public Lokalizacja
{
public:
	Wioska();
	Wioska(Postac*);
	~Wioska();

	void start();
	void wczytajDane();
};

