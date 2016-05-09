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
	if (bron = 0)
	{
		return atak;
	}
	else
	{
		return atak + bron->atak;
	}
}

int Postac::getZasieg(void)
{
	if (bron = 0)
	{
		return zasieg;
	}
	else
	{
		return bron->zasieg;
	}
}

int Postac::getSzybkosc(void)
{
	if (bron = 0)
	{
		return szybkosc;
	}
	else
	{
		return szybkosc + bron->szybkosc;
	}
}

int Postac::getSzczescie(void)
{
	if (bron = 0)
	{
		return szczescie;
	}
	else
	{
		return szczescie + bron->szczescie;
	}
}

int Postac::getObrazenia(void)
{
	if (bron = 0)
	{
		return obrazenia;
	}
	else
	{
		return obrazenia + bron->obrazenia;
	}
}
