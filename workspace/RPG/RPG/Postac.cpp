#include "Postac.h"
#include "Bron.h"
#include "Przedmiot.h"
#include "Pancerz.h"


Postac::Postac()
{
	this->imie = "Bezimienny";
}

Postac::Postac(string imie, string klasa, Bron* bron)
{
	this->imie = imie;
	this->klasa_postaci = klasa;
	quest = 0;
	this->bron = bron;
	pancerz = 0;
}


Postac::~Postac()
{
}

void Postac::zmienBron(Bron * bron)
{
	this->bron = bron;
}

void Postac::zmienPancerz(Pancerz * pancerz)
{
	this->pancerz = pancerz;
}

int Postac::getAtak(void)
{
	if (this->bron == 0)
	{
		return this->atak;
	}
	else
	{
		return this->atak + this->bron->atak;
	}
}

int Postac::getZasieg(void)
{
	if (this->bron == 0)
	{
		return this->zasieg;
	}
	else
	{
		return (this->bron)->zasieg;
	}
}

int Postac::getSzybkosc(void)
{
	if (this->bron == 0)
	{
		return this->szybkosc;
	}
	else
	{
		return this->szybkosc + this->bron->szybkosc;
	}
}

int Postac::getSzczescie(void)
{
	if (bron == 0)
	{
		if (pancerz == 0)
			return this->szczescie;
		else
			return this->szczescie + this->pancerz->szczescie;
	}
	else
	{
		if (pancerz == 0)
			return this->szczescie + this->bron->szczescie;
		else
			return this->szczescie + this->bron->szczescie + this->pancerz->szczescie;
	}
}

int Postac::getObrazenia(void)
{
	if (this->bron == 0)
	{
		return this->obrazenia;
	}
	else
	{
		return this->obrazenia + this->bron->obrazenia;
	}
}

int Postac::getObrona(void)
{
	if (pancerz == 0)
		return this->obrona;
	else
		return this->obrona + this->pancerz->obrona;
}

int Postac::getKlasaPancerza(void)
{
	if (pancerz == 0)
		return this->klasa_pancerza;
	else
		return this->klasa_pancerza +this->pancerz->klasaPancerza;
}

int Postac::getMaxZdrowie(void)
{
	if (pancerz == 0)
		return this->max_zdrowie;
	else
		return this->max_zdrowie +this->pancerz->maxZdrowie;
}

int Postac::getMaxWytrzymalosc(void)
{
	if (pancerz == 0)
		return this->max_wytrzymalosc;
	else
		return this->max_wytrzymalosc + this->pancerz->maxWytrzymalosc;
}
