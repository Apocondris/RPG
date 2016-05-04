#pragma once
#include <iostream>
#include <string>
using namespace std;

class Quest
{
public:
	Quest(string nazwaKlucza, int ilosc);

	string nazwaQuesta;
	string opis;
	string nazwaKlucza;
	int ilosc;
	int aktualnaIlosc;
};
