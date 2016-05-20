#pragma once

#include "Npc.h"


class Karczmarz : public Npc
{
public:
	Karczmarz(shared_ptr<Postac>);

	void start(void);

private:
	static const int iloscImion = 6;
	static const int iloscPowitan = 6;
	static const int iloscLokalnychPlotek = 6;
	static const int iloscRad = 25;
	static string listaImion[iloscImion];
	static string listaPowitan[iloscPowitan];
	static string listaLokalnychPlotek[iloscLokalnychPlotek];
	static string listaRad[iloscRad];
	string lokalnaPlotka;

	void menuGlowne(bool &przebywaszUKarczmarza);
	void logo();

};
