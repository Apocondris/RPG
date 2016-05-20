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
	Szlak(shared_ptr<Postac>, shared_ptr<Lokalizacja>);
	~Szlak();

	void start(void);

private:
	static const int iloscNazwSzlakow = 15;
	static const int iloscPrzeciwnikow = 3;
	static string nazwySzlakow[iloscNazwSzlakow];
	Przeciwnik * tablicaPrzeciwnikow[iloscPrzeciwnikow]; 

	void menuGlowne(bool &);
	void poluj();
	//do zrobienia walka i losowanie potwor�w na danym szlaku
	shared_ptr<Lokalizacja> losujLokalizacje(shared_ptr<Postac>);
	Przeciwnik * losujPrzeciwnika(void);
	void losujPrzeciwnikow(Przeciwnik * tablica[iloscPrzeciwnikow]);
	void odswiezPrzeciwnika(short losowaLiczba);
	void logo(void);
};

