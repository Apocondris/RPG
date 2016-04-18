#pragma once

#ifndef WIOSKA_H
#define WIOSKA_H

#include "Lokalizacja.h"

static class Wioska : public Lokalizacja
{
public:
	Wioska();
	Wioska(Postac*);
	Wioska(Postac*, Lokalizacja*);
	~Wioska();

	void start(void);

protected:

	Postac * karczmarz;

	void menuGlowne(bool &);

private:
	Lokalizacja * losujLokalizacje(Postac *);

};

#endif