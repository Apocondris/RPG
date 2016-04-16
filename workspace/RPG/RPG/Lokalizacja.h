#pragma once

#ifndef LOKALIZACJA_H
#define LOKALIZACJA_H

#include "Postac.h"
#include "Gra.h"

static class Lokalizacja
{

public:
	Postac* postac;
	string nazwa;

	Lokalizacja();
	Lokalizacja(Postac*);
	virtual ~Lokalizacja();

	virtual void start();
};

#endif // LOKALIZACJA_H