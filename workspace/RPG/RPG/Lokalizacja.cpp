#include "Lokalizacja.h"

Lokalizacja::Lokalizacja()
{
	this->postac = new Postac;
}


Lokalizacja::Lokalizacja(Postac* postac)
{
	this->postac = postac;
}


Lokalizacja::~Lokalizacja()
{
}
