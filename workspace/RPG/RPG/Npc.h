#pragma once

#include "WszystkieKlasy.h"
#include <fstream>
#include <string>
#include <iostream>
#include <memory>
using namespace std;

class Npc
{
public:

	Npc();
	Npc(shared_ptr<Postac>);

	virtual void start();

protected:
	shared_ptr<Postac> postac;
	string imie;
	string powitanie;
	bool zapytanoOImie;

	void czyscEkran();

	bool czyListaJestPusta(int liczba, string * lista);
	void ladujDaneNpc(string sciezka, string * tablica, const int iloscDanych);
	string pobierzInformacje(const int liczbaDostepnych, string * listaDanych);
};

