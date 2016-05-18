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
	~Lokalizacja();

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
	virtual void przegladajEkwipunek(void);
	virtual void menuPrzegladaniaEkwipunku(bool&);
	virtual void menuZdejmowaniaEkwipunku(bool&);
	virtual void menuZakladaniaEkwipunku(bool&);
	virtual void rozdanieExpa(void);
	virtual void menuRozdaniaExpa(bool&);

	virtual bool czyNazwyLokalizacjiSaPuste(string * nazwyLokalizacji, int iloscNazw);
	virtual void ladujNazwyLokalizacji(string sciezka, string * nazwyLokalizacji, int iloscNazw);
	virtual string pobierzNazwe(string * nazwyLokalizacji, int iloscNazw);
	void logoKarczmy();
	void logoTablicyOgloszen();
};

#endif