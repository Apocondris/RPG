#pragma once

#include "Przedmiot.h"

class PrzedmiotDoQuesta : public Przedmiot
{
public:
	PrzedmiotDoQuesta(unsigned short wartosc, string nazwa);

	string toString(void);
};

