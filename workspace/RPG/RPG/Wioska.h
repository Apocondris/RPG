#pragma once

#ifndef WIOSKA_H
#define WIOSKA_H

#include "Lokalizacja.h"

class Wioska : public Lokalizacja
{
public:
	Wioska();
	Wioska(Postac*);
	Wioska(Postac*, Lokalizacja*);
	~Wioska();
	void start(void);

private:
	void menuGlowne(bool &);
	static string nazwyWiosek[iloscNazw];

	Lokalizacja * losujLokalizacje(Postac *);
	string logo();
};

#endif