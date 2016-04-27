#pragma once

#include "Lokalizacja.h"
#include "Przeciwnik.h"
#include "WszystkieKlasy.h"
#include <iostream>
#include <string>
using namespace std;

class Szlak : public Lokalizacja
{
public:
	Szlak(Postac*, Lokalizacja*);

	void start();
private:

	static const int iloscNazwSzlakow = 15;
	static const int iloscPrzeciwnikow = 3;
	static string nazwySzlakow[iloscNazwSzlakow];
	Przeciwnik * tablicaPrzeciwnikow[iloscPrzeciwnikow]; 

	void menuGlowne(bool &);
	void poluj(Postac*);
	//do zrobienia walka i losowanie potworów na danym szlaku
	Lokalizacja * losujLokalizacje(Postac *);
	void losujPrzeciwnikow(Przeciwnik * tablica[iloscPrzeciwnikow]);
	void logo(void);
};

