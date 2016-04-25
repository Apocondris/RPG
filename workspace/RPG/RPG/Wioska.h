#pragma once

#ifndef WIOSKA_H
#define WIOSKA_H

#include "Lokalizacja.h"
#include "Szlak.h"

const int iloscNazwWiosek = 5;

class Wioska : public Lokalizacja
{
public:
	Wioska();
	Wioska(Postac*);
	Wioska(Postac*, Lokalizacja*);
	~Wioska();
	void start(void);

private:
	static string nazwyWiosek[iloscNazwWiosek];

	void menuGlowne(bool &);

	string logo();
};

#endif