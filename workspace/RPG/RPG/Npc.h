#pragma once

#include "Postac.h"
#include <fstream>

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
	bool zapotanoOImie = false;

	void czyscEkran();

	bool czyListaJestPusta(int liczba, string * lista);
	void ladujDaneNpc(string sciezka, string * tablica, const int iloscDanych);
	string pobierzInformacje(const int liczbaDostepnych, string * listaDanych);
};

