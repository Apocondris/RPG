#pragma once

#ifndef LOKALIZACJA_H
#define LOKALIZACJA_H

#include "Postac.h"

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
};

#endif