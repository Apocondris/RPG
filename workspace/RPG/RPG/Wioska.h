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

protected:
	Postac * karczmarz;

	void menuGlowne(bool &);

private:
	static string nazwyWiosek[iloscNazw];

	Lokalizacja * losujLokalizacje(Postac *);
	void ladujNazwyWiosek();
	bool czyNazwyLokalizacjiSaPuste();
	string pobierzNazwe();
};

#endif