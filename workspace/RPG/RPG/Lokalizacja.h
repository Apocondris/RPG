#pragma once

#ifndef LOKALIZACJA_H
#define LOKALIZACJA_H

#include "Postac.h"
#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>

const int iloscNazw = 5;

class Lokalizacja
{
public:
	Postac* postac;
	string nazwa;

	Lokalizacja();
	Lokalizacja(Postac*);
	Lokalizacja(Postac*,Lokalizacja*);
	virtual ~Lokalizacja();

	virtual void start(void);

protected:
	Lokalizacja * przybytoZ;
	Lokalizacja * idzDo;

	void czyscEkran(void);
	void karczma(void);
	void menuKarczmy(bool&);

	bool czyNazwyLokalizacjiSaPuste();
	void ladujNazwyWiosek();
	string pobierzNazwe();
};

#endif