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

	Lokalizacja();
	Lokalizacja(Postac*);
	Lokalizacja(Postac*,Lokalizacja*);
	virtual ~Lokalizacja();

	virtual void start(void);

protected:
	Postac* postac;
	string nazwa;
	Lokalizacja * przybytoZ;
	Lokalizacja * idzDo;
	static string nazwyLokalizacji[iloscNazw];

	void czyscEkran(void);
	virtual void karczma(void);
	virtual void menuKarczmy(bool&);

	virtual bool czyNazwyLokalizacjiSaPuste();
	virtual void ladujNazwyLokalizacji(string);
	virtual string pobierzNazwe();
};

#endif