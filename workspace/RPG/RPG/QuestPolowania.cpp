#include "QuestPolowania.h"
#include "BandytaLucznik.h"
#include "BandytaWojownik.h"
#include "Dzik.h"
#include "Wilk.h"
#include "Niedzwiedz.h"
#include "Utopiec.h"
#include <ctime>



QuestPolowania::QuestPolowania()
{
	
	int iloscCelow = rand() % 10 + 5; //ilosc dostepnych przeciwników
	Przeciwnik * nazwaCelu = losujCelPolowania();
	nazwaQuesta = "Upoluj";
	opis = "Poszukuje smialka ktory wytropi i zabije " + to_string(iloscCelow) + "x " + nazwaCelu->nazwa;
	nazwaKlucza = nazwaCelu->nazwa;
	ilosc = iloscCelow;
	nagroda = ilosc * nazwaCelu->wartosc;
	doswiadczenie = nagroda * 2.5;
}


Przeciwnik * QuestPolowania::losujCelPolowania(void)
{//cout << "Losowanie przeciwnikow:" << endl;
	
	int losowaLiczba = rand() % 5; //po % podaæ liczbê dostêpnych przeciwnikow
	switch (losowaLiczba)
	{
		case 0:
		{
			return new BandytaLucznik();
			break;
		}
		case 1:
		{
			return new BandytaWojownik();
			break;
		}
		case 2:
		{
			return new Dzik();
			break;
		}
		case 3:
		{
			return new Niedzwiedz();
			break;
		}
		case 4:
		{
			return new Utopiec();
			break;
		}
		case 5:
		{
			return new Wilk();
			break;
		}
	}
}