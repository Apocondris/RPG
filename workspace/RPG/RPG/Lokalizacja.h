#pragma once

#ifndef LOKALIZACJA_H
#define LOKALIZACJA_H

#include "WszystkieKlasy.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;


class Lokalizacja
{
public:
	Lokalizacja(Postac*);
	Lokalizacja(Postac*,Lokalizacja*);

	virtual void start(void);

protected:
	Postac * postac;
	Karczmarz * karczmarz;

	string nazwa;
	Lokalizacja * przybytoZ;
	Lokalizacja * idzDo;

	void czyscEkran(void);
	virtual void karczma(void);
	virtual void menuKarczmy(bool&);
	virtual void tablicaOgloszen(void);
	virtual void menuTablicyOgloszen(bool&);

	virtual bool czyNazwyLokalizacjiSaPuste(string * nazwyLokalizacji, int iloscNazw);
	virtual void ladujNazwyLokalizacji(string sciezka, string * nazwyLokalizacji, int iloscNazw);
	virtual string pobierzNazwe(string * nazwyLokalizacji, int iloscNazw);
	virtual Przeciwnik * losujCelePolowania(void);
	void logoKarczmy();
	void logoTablicyOgloszen();
};

#endif