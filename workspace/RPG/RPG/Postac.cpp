#include "Postac.h"
#include "Bron.h"



Postac::Postac()
{
	this->imie = "Bezimienny";
}

Postac::Postac(string imie,string klasa)
{
	this->imie = imie;
	this->klasa_postaci = klasa;
	quest = 0;
}


Postac::~Postac()
{
}

int Postac::getAtak(void)
{
	if (this->bron = 0)
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
	if (this->bron = 0)
	{
		return this->zasieg;
	}
	else
	{
		return this->bron->zasieg;
	}
}

int Postac::getSzybkosc(void)
{
	if (this->bron = 0)
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
	if (bron = 0)
	{
		return this->szczescie;
	}
	else
	{
		return this->szczescie + this->bron->szczescie;
	}
}

int Postac::getObrazenia(void)
{
	if (this->bron = 0)
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
	return this->obrona;
}

int Postac::getKlasaPancerza(void)
{
	return this->klasa_pancerza;
}
