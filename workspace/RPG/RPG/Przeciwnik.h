#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include "WszystkieKlasy.h"
using namespace std;

class Przeciwnik
{
public:
	Przeciwnik();
	~Przeciwnik();

	string nazwa;
	int zdrowie;
	int klasa_pancerza;
	int szybkosc;
	int szczescie;
	int atak;
	int obrona;
	int wytrzymalosc;
	int zasieg;
	int obrazenia;
};

