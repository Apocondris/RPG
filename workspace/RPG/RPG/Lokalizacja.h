#pragma once

#ifndef LOKALIZACJA_H
#define LOKALIZACJA_H

#include "Postac.h"
#include "Karczmarz.h"
#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>


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
	Karczmarz* karczmarz = 0;

	string nazwa;
	Lokalizacja * przybytoZ = 0;
	Lokalizacja * idzDo = 0;

	void czyscEkran(void);
	virtual void karczma(void);
	virtual void menuKarczmy(bool&);

	virtual bool czyNazwyLokalizacjiSaPuste(string * nazwyLokalizacji, int iloscNazw);
	virtual void ladujNazwyLokalizacji(string sciezka, string * nazwyLokalizacji, int iloscNazw);
	virtual string pobierzNazwe(string * nazwyLokalizacji, int iloscNazw);
	string logoKarczmy();
};

#endif