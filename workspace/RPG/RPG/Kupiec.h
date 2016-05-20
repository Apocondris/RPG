#pragma once

#include "Npc.h"
#include "WszystkieKlasy.h"

class Kupiec : public Npc
{
public:
	Kupiec(shared_ptr<Postac>);

	void start(void);

private:
	static const int iloscImion = 6;
	static const int iloscPowitan = 6;
	static string listaImion[iloscImion];
	static string listaPowitan[iloscPowitan];

	void menuGlowne(bool &przebywaszUKupca);
	void kupowanie(void);
	void menuKupowania(bool &kupujesz);
	void sprzedaz(void);
	void menuSprzedazy(bool &sprzedajesz);
	void logo();
};

