#include "Miasto.h"
#include "Szlak.h"
#include "Postac.h"
#include <Windows.h>

string Miasto::nazwyMiast[iloscNazwMiast];

Miasto::Miasto(shared_ptr<Postac> postac) : Lokalizacja(postac)
{
	if (czyNazwyLokalizacjiSaPuste(nazwyMiast, iloscNazwMiast))
	{
		ladujNazwyLokalizacji("NazwyMiast.txt", nazwyMiast, iloscNazwMiast);
	}
	this->nazwa = pobierzNazwe(nazwyMiast, iloscNazwMiast);
	this->kupiec = 0;
}

Miasto::Miasto(shared_ptr<Postac> postac, shared_ptr<Lokalizacja> lokalizacja) : Lokalizacja(postac, lokalizacja)
{
	if (czyNazwyLokalizacjiSaPuste(nazwyMiast, iloscNazwMiast))
	{
		ladujNazwyLokalizacji("NazwyMiast.txt", nazwyMiast, iloscNazwMiast);
	}
	this->nazwa = pobierzNazwe(nazwyMiast, iloscNazwMiast);
	this->kupiec = 0;
}

void Miasto::start(void)
{
	bool przebywaszWMiescie = true;

	while (przebywaszWMiescie)
	{
		czyscEkran();
		logo();
		menuGlowne(przebywaszWMiescie);
	}
}

void Miasto::menuGlowne(bool & przebywaszWMiescie)
{
	short wybor;
	cout << "Znajdujesz sie w miescie " << this->nazwa << ".." << endl
		<< "Co chcesz zrobic?" << endl
		<< "1) Idz do karczmy" << endl
		<< "2) Idz do kupca" << endl
		<< "3) Podrozuj dalej" << endl;
	if (przybytoZ != 0) cout << "4) Wroc do poprzedniej lokalizacji" << endl;
	cin >> wybor;
	if (cin.fail()) { cout << "Nie jestes zbyt rozgarniety, prawda?" << endl; cin.clear(); }
	cin.ignore(100000, '\n');

	switch (wybor)
	{
		case 1:
		{
			karczma();
			break;
		}
		case 2:
		{
			if (kupiec == 0) kupiec = make_unique<Kupiec>(postac);
			kupiec->start();
			break;
		}
		case 3:
		{
			if (idzDo == 0)
			{
				idzDo = make_shared<Szlak>(postac, shared_ptr<Miasto>(this));
			}
			idzDo->start();
			break;
		}
		case 4:
		{
			if (przybytoZ != 0)
			{
				przebywaszWMiescie = false;
			}
		}
	}
}

void Miasto::logo()
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
