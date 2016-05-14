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
	~Szlak();

	void start();

private:
	static const int iloscNazwSzlakow = 15;
	static const int iloscPrzeciwnikow = 3;
	static string nazwySzlakow[iloscNazwSzlakow];
	Przeciwnik * tablicaPrzeciwnikow[iloscPrzeciwnikow]; 

	void menuGlowne(bool &);
	void poluj();
	//do zrobienia walka i losowanie potworów na danym szlaku
	Lokalizacja * losujLokalizacje(Postac *);
	Przeciwnik * losujPrzeciwnika(void);
	void losujPrzeciwnikow(Przeciwnik * tablica[iloscPrzeciwnikow]);
	void odswiezPrzeciwnika(short losowaLiczba);
	void logo(void);
};

