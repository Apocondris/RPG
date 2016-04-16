#include "Wioska.h"



Wioska::Wioska()
{
}

Wioska::Wioska(Postac * postac) : Lokalizacja(postac)
{
	nazwa = "wioska";
	wczytajDane();
}


Wioska::~Wioska()
{
}

void Wioska::start()
{
	Gra::czyscEkran();
}
