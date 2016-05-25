#include "QuestPolowania.h"
#include "BandytaLucznik.h"
#include "BandytaWojownik.h"
#include "Dzik.h"
#include "Wilk.h"
#include "Niedzwiedz.h"
#include "Utopiec.h"



QuestPolowania::QuestPolowania()
{
	
	int iloscCelow = rand() % 10 + 5; //ilosc dostepnych przeciwników
	shared_ptr<Przeciwnik> nazwaCelu = losujCelPolowania();
	nazwaQuesta = "Upoluj";
	opis = "Poszukuje smialka ktory wytropi i zabije " + to_string(iloscCelow) + "x " + nazwaCelu->nazwa;
	nazwaKlucza = nazwaCelu->nazwa;
	ilosc = iloscCelow;
	nagroda = ilosc * nazwaCelu->wartosc;
	doswiadczenie = nagroda * 2.5;
}


shared_ptr<Przeciwnik>QuestPolowania::losujCelPolowania(void)
{//cout << "Losowanie przeciwnikow:" << endl;
	
	int losowaLiczba = rand() % 5; //po % podaæ liczbê dostêpnych przeciwnikow
	switch (losowaLiczba)
	{
		case 0:
		{
			return make_shared<BandytaLucznik>();
			break;
		}
		case 1:
		{
			return make_shared<BandytaWojownik>();
			break;
		}
		case 2:
		{
			return make_shared<Dzik>();
			break;
		}
		case 3:
		{
			return make_shared<Niedzwiedz>();
			break;
		}
		case 4:
		{
			return make_shared<Utopiec>();
			break;
		}
		case 5:
		{
			return make_shared<Wilk>();
			break;
		}
	}
}