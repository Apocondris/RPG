#pragma once
#include "WszystkieKlasy.h"
#ifndef POSTAC_H
#define POSTAC_H

#include <iostream>
#include <string>
#include <map>
using namespace std;

class Postac
{
public:
	string imie;

	Postac();
	Postac(string, string);
	~Postac();
	int zdrowie;
	int punktyDoWydania;
	int klasa_pancerza;
	int szybkosc;
	int szczescie;
	int atak;
	int obrona;
	int wytrzymalosc;
	int zasieg;
	int obrazenia;
	int max_zdrowie;
	int max_wytrzymalosc;
	string klasa_postaci;
	int strzaly;

	Quest * quest;
	unsigned int posiadaneZloto;
	map<string, int> przedmiotyDoQuestow;
};

#endif