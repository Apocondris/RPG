#pragma once
#include <iostream>
#include <string>
using namespace std;

class Quest
{
public:
	Quest();

	string nazwaQuesta;
	string opis;
	string nazwaKlucza;
	int ilosc;
	int aktualnaIlosc;
	unsigned short nagroda;
	unsigned int doswiadczenie;
};
