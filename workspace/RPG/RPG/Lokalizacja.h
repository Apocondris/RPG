#pragma once

#ifndef LOKALIZACJA_H
#define LOKALIZACJA_H

#include "WszystkieKlasy.h"
#include "Karczmarz.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <memory>
using namespace std;


class Lokalizacja
{
public:
	Lokalizacja(shared_ptr<Postac>);
	Lokalizacja(shared_ptr<Postac>,shared_ptr<Lokalizacja>);

	virtual void start(void);

protected:
	shared_ptr<Postac> postac;
	unique_ptr<Karczmarz> karczmarz;

	string nazwa;
	shared_ptr<Lokalizacja> przybytoZ;
	shared_ptr<Lokalizacja> idzDo;

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