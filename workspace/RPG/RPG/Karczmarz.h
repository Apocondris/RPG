#pragma once

#include "Npc.h"

const int iloscImion = 6;
const int iloscPowitan = 6;

class Karczmarz : public Npc
{
public:
	Karczmarz();
	Karczmarz(Postac*);
	~Karczmarz();

	void start(void);
	void menuGlowne(bool &przebywaszUKarczmarza);

	string logo();

private:

	static string listaImion[];
	static string listaPowitan[];

};
