#pragma once

#include "Lokalizacja.h"
#include "Wioska.h"
#include "Postac.h"
#include "Przeciwnik.h"


const int iloscNazwSzlakow = 15;
const int iloscPrzeciwnikow = 3;

class Szlak : public Lokalizacja
{
public:

	Szlak();
	Szlak(Postac*);
	Szlak(Postac*, Lokalizacja*);
	~Szlak();

	void start();
private:
	static string nazwySzlakow[iloscNazwSzlakow];
	Przeciwnik tablicaPrzeciwnikow[iloscPrzeciwnikow]; 

	void menuGlowne(bool &);
	void poluj(Postac*);
	//do zrobienia walka i losowanie potworów na danym szlaku
	Lokalizacja * losujLokalizacje(Postac *);
	string logo(void);
};

