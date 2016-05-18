#pragma once

#include "WszystkieKlasy.h"
#include "Przedmiot.h"

class Pancerz : public Przedmiot
{
public:
	Pancerz(string nazwa, int szczescie, int obrona, int klasaPancerza, int maxZdrowie, int maxWytrzymalosc);

	int szczescie;
	int obrona;
	int klasaPancerza;
	int maxZdrowie;
	int maxWytrzymalosc;

	string toString(void);
};

