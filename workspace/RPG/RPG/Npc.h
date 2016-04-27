#pragma once

#include "WszystkieKlasy.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

class Npc
{
public:

	Npc();
	Npc(Postac*);
	~Npc();

	virtual void start();

protected:
	Postac * postac;
	string imie;
	string powitanie;
	bool zapytanoOImie;

	void czyscEkran();

	bool czyListaJestPusta(int liczba, string * lista);
	void ladujDaneNpc(string sciezka, string * tablica, const int iloscDanych);
	string pobierzInformacje(const int liczbaDostepnych, string * listaDanych);
};

