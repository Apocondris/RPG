#include "Szlak.h"
#include "Wioska.h"
#include "Postac.h"
#include <Windows.h>
#include "BandytaLucznik.h"
#include "BandytaWojownik.h"
#include "Dzik.h"
#include "Wilk.h"
#include "Niedzwiedz.h"


string Szlak::nazwySzlakow[iloscNazwSzlakow];

Szlak::Szlak(Postac * postac, Lokalizacja * lokalizacja) : Lokalizacja(postac, lokalizacja)
{
	if (czyNazwyLokalizacjiSaPuste(nazwySzlakow, iloscNazwSzlakow))
	{
		ladujNazwyLokalizacji("NazwySzlakow.txt", nazwySzlakow, iloscNazwSzlakow);
	}
	this->nazwa = pobierzNazwe(nazwySzlakow, iloscNazwSzlakow);
	losujPrzeciwnikow(tablicaPrzeciwnikow);
}

void Szlak::start()
{
	bool przebywaszNaSzlaku = true;

	while (przebywaszNaSzlaku)
	{
		czyscEkran();
		logo();
		menuGlowne(przebywaszNaSzlaku);
	}
}

void Szlak::menuGlowne(bool &przebywaszNaSzlaku)
{
	short wybor;
	cout << "Znajdujesz sie w wiosce " << this->nazwa << ".." << endl
		<< "Co chcesz zrobic?" << endl
		<< "1) Poluj" << endl
		<< "2) Podrozuj dalej" << endl
		<< "3) Wroc do poprzedniej lokalizacji" << endl;
	cin >> wybor;
	if (cin.fail()) { cout << "Nie jestes zbyt rozgarniety, prawda?" << endl; cin.clear(); }
	cin.ignore(100000, '\n');

	switch (wybor)
	{
	case 1:
	{
		poluj(postac);
		break;
	}
	case 2:
	{
		if (idzDo == 0)
		{
			idzDo = losujLokalizacje(postac);
		}
		idzDo->start();
		break;
	}
	case 3:
	{
		if (przybytoZ != 0)
		{
			przebywaszNaSzlaku = false;
		}
	}
	}
}

void Szlak::poluj(Postac *)
{
	czyscEkran();
	int losowaLiczba = rand() % iloscPrzeciwnikow;
	cout << "Walczysz z " << tablicaPrzeciwnikow[losowaLiczba]->nazwa << endl;
	system("pause");
	//walka z przeciwnikiem
}

Lokalizacja * Szlak::losujLokalizacje(Postac *)
{
	int losowaLiczba = rand() % 1; //po % podaæ liczbê dostêpnych lokalizacji
	switch (losowaLiczba)
	{
		case 0:
		{
			return new Wioska(postac, this);
			break;
		}
		default:
		{
			return new Lokalizacja(postac, this);
			break;
		}
	}
}

void Szlak::losujPrzeciwnikow(Przeciwnik * tablica[iloscPrzeciwnikow])
{

	int losowaLiczba = rand() % 5; //po % podaæ liczbê dostêpnych przeciwnikow
	for (int i = 0; i < iloscPrzeciwnikow; i++)
	{
		switch (losowaLiczba)
		{
			case 0:
			{
				tablica[i] = new BandytaLucznik();
				break;
			}
			case 1:
			{
				tablica[i] = new BandytaWojownik();
				break;
			}
			case 2:
			{
				tablica[i] = new Wilk();
				break;
			}
			case 3:
			{
				tablica[i] = new Dzik();
				break;
			}
			case 4:
			{
				tablica[i] = new Niedzwiedz();
				break;
			}
			default:
			{

				break;
			}
		}
	}
}

void Szlak::logo(void)
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, 240);
	//100 x 12
	string wynik = "";
	wynik += "                                                                                                    ";
	wynik += "                                                                                                    ";
	wynik += "                                                                                                    ";
	wynik += "                                                                                                    ";
	wynik += "                                                                                                    ";
	wynik += "                            cos tu trzeba zrobic                                                    ";
	wynik += "                                                                                                    ";
	wynik += "                                                                                                    ";
	wynik += "                                                                                                    ";
	wynik += "                                                                                                    ";
	wynik += "                                                                                                    ";
	wynik += "                                                                                                    ";
	wynik += "----------------------------------------------------------------------------------------------------";
	cout << wynik << endl;
	SetConsoleTextAttribute(hOut, 15);
}
