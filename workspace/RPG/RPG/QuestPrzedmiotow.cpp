#include "QuestPrzedmiotow.h"
#include "Przedmiot.h"
#include "PrzedmiotDoQuesta.h"
#include <ctime>

QuestPrzedmiotow::QuestPrzedmiotow()
{
	srand(time(NULL));
	int iloscCelow = rand() % 4 + 1; //ilosc dostepnych przeciwników
	Przedmiot * przedmiot = losujCel();
	nazwaQuesta = "Przynies";
	opis = "Porzebuje kogos, kto dostarczy mi " + to_string(iloscCelow) + "x " + przedmiot->nazwa;
	nazwaKlucza = przedmiot->nazwa;
	ilosc = iloscCelow;
	nagroda = ilosc * przedmiot->wartosc;
	doswiadczenie = nagroda * 2.5;
}

Przedmiot * QuestPrzedmiotow::losujCel(void)
{//cout << "Losowanie przeciwnikow:" << endl;
	srand(time(NULL));
	int losowaLiczba = rand() % 5; //po % podaæ liczbê dostêpnych przeciwnikow
	switch (losowaLiczba)
	{
		case 0:
		{
			return new PrzedmiotDoQuesta(20, "Skora wilka");
			break;
		}
		case 1:
		{
			return new PrzedmiotDoQuesta(30, "Skora utopca");
			break;
		}
		case 2:
		{
			return new PrzedmiotDoQuesta(40, "Skora dzika");
			break;
		}
		case 3:
		{
			return new PrzedmiotDoQuesta(50, "Skora niedzwiedzia");
			break;
		}
		case 4:
		{
			return new PrzedmiotDoQuesta(20, "Zloty zab");
			break;
		}
	}
	return 0;
}