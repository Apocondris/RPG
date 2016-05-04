#include "Postac.h"



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
