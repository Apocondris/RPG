#pragma once

#include "WszystkieKlasy.h"
#include <iostream>
#include <string>

using namespace std;

class FabrykaWyposazenia
{
public:
	static Bron * stworzMiecz(int zasieg = 1, int obrazenia = 10, int szybkosc=0, int szczescie=0, int atak=0);
	static Bron * stworzLuk(int zasieg = 10, int obrazenia = 5, int szybkosc = 0, int szczescie = 0, int atak = 0);
	static Pancerz * stworzPancerz(int szczescie = 0, int obrona = 0, int klasaPancerza = 0, int maxZdrowie = 0, int maxWytrzymalosc = 0);
	static Bron * generujMiecz();
	static Bron * generujLuk();
	static Pancerz * generujPancerz();
	static Przedmiot * generujWyposazenie();

};

