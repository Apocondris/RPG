#pragma once
#include "WszystkieKlasy.h"
#include "Przedmiot.h"

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
	Postac(string, string, Bron*);
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
	unsigned int aktualneDoswadczenie;
	unsigned int doswiadczenieDoNastepnegoPoziomu;

	Quest * quest;
	unsigned int posiadaneZloto;
	map<string, int> przedmiotyDoQuestow;
	Bron * bron;
	Pancerz * pancerz;
	static const int wielkoscEkwipunku = 15;
	Przedmiot * ekwipunek[wielkoscEkwipunku];

	virtual void zmienBron(Bron *);
	virtual void zmienPancerz(Pancerz *);
	virtual void dodajPrzedmiotDoEkwipunku(Przedmiot *);
	virtual void usunPrzedmiotZEkwipunku(Przedmiot *);
	virtual void usunPrzedmiotZEkwipunku(unsigned short);
	virtual Przedmiot wyciagPrzedmiotZEkwipunku(Przedmiot *);
	virtual Przedmiot wyciagPrzedmiotZEkwipunku(unsigned short);

	virtual void przydzielDoswiadczenie(unsigned int);

	int getAtak(void);
	int getZasieg(void);
	int getSzybkosc(void);
	int getSzczescie(void);
	int getObrazenia(void);
	int getObrona(void);
	int getKlasaPancerza(void);
	int getMaxZdrowie(void);
	int getMaxWytrzymalosc(void);
};

#endif