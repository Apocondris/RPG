#pragma once

#ifndef WIOSKA_H
#define WIOSKA_H

#include "Lokalizacja.h"
#include "WszystkieKlasy.h"

class Wioska : public Lokalizacja
{
public:
	Wioska(Postac*);
	Wioska(Postac*, Lokalizacja*);

	void start(void);

private:
	static const int iloscNazwWiosek = 5;
	static string nazwyWiosek[iloscNazwWiosek];

	void menuGlowne(bool &);

	void logo();
};

#endif