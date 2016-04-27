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

	void atakuj(Postac *);
	void ruch(Postac *);
};

