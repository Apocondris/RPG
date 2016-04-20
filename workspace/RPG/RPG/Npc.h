#pragma once

#include "Postac.h"
#include <fstream>

const int iloscImion = 5;
const int iloscPowitan = 5;

class Npc
{
public:

	Npc();
	Npc(Postac*);
	~Npc();

	virtual void start(Postac*);

protected:
	Postac * postac;
	string imie;
	string powitanie;
	static string listaImion[];
	static string listaPowitan[];

	void czyscEkran();

	bool czyListaImionJestPusta();
	bool czyListaPowitanJestPusta();
	void ladujDaneNpc(string, string*, const int);
	string pobierzImie();
	string pobierzPowitanie();
};

