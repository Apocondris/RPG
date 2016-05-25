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

	void start(void);

private:
	static const int iloscNazwSzlakow = 15;
	static const int iloscPrzeciwnikow = 3;
	static string nazwySzlakow[iloscNazwSzlakow];
	shared_ptr<Przeciwnik>tablicaPrzeciwnikow[iloscPrzeciwnikow]; 

	void menuGlowne(bool &);
	void poluj();
	//do zrobienia walka i losowanie potworów na danym szlaku
	shared_ptr<Lokalizacja> losujLokalizacje(shared_ptr<Postac>);
	shared_ptr<Przeciwnik> losujPrzeciwnika(void);
	void losujPrzeciwnikow(shared_ptr<Przeciwnik>tablica[iloscPrzeciwnikow]);
	void odswiezPrzeciwnika(short losowaLiczba);
	void logo(void);
};

