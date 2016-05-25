#pragma once

#include "WszystkieKlasy.h"
#include "Lokalizacja.h"

class Bagna : public Lokalizacja
{
public:
	Bagna(shared_ptr<Postac>, shared_ptr<Lokalizacja>);

	void start(void);

private:
	shared_ptr<Przeciwnik>przeciwnik;
	static const int iloscNazwBagien = 5;
	static string nazwyBagien[iloscNazwBagien];

	void menuGlowne(bool &);
	void poluj();

	void logo();
};

