#pragma once

#include "WszystkieKlasy.h"
#include "Przedmiot.h"

class Pancerz : public Przedmiot
{
public:
	Pancerz();

	int szczescie;
	int obrona;
	int klasaPancerza;
	int maxZdrowie;
	int maxWytrzymalosc;
};

