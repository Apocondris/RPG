#include "Wioska.h"
#include "Szlak.h"
#include "Postac.h"
#include <windows.h>

string Wioska::nazwyWiosek[iloscNazwWiosek];

Wioska::Wioska(Postac * postac) : Lokalizacja(postac)
{
	if (czyNazwyLokalizacjiSaPuste(nazwyWiosek, iloscNazwWiosek))
	{
		ladujNazwyLokalizacji("NazwyWiosek.txt", nazwyWiosek, iloscNazwWiosek);
	}
	this->nazwa = pobierzNazwe(nazwyWiosek, iloscNazwWiosek);
}

Wioska::Wioska(Postac * postac, Lokalizacja * lokalizacja) : Lokalizacja(postac, lokalizacja)
{
	if (czyNazwyLokalizacjiSaPuste(nazwyWiosek, iloscNazwWiosek))
	{
		ladujNazwyLokalizacji("NazwyWiosek.txt", nazwyWiosek, iloscNazwWiosek);
	}
	this->nazwa = pobierzNazwe(nazwyWiosek, iloscNazwWiosek);
}

void Wioska::start(void)
{
	bool przebywaszWWiosce = true;

	//czyscEkran();
	//cout << "Przybyles do wioski "<< this->nazwa << ".." << endl;
	//system("pause");

	while (przebywaszWWiosce)
	{
		czyscEkran();
		logo();
		menuGlowne(przebywaszWWiosce);
	}
}

void Wioska::menuGlowne(bool & przebywaszWWiosce)
{
	short wybor;
	cout << "Znajdujesz sie w wiosce " << this->nazwa << ".." << endl
		<< "Co chcesz zrobic?" << endl
		<< "1) Idz do karczmy" << endl
		<< "2) Podrozuj dalej" << endl;
	if (przybytoZ != 0) cout << "3) Wroc do poprzedniej lokalizacji" << endl;
	cin >> wybor;
	if (cin.fail()) { cout << "Nie jestes zbyt rozgarniety, prawda?" << endl; cin.clear(); }
	cin.ignore(100000, '\n');

	switch (wybor)
	{
		case 1 :
		{
			karczma();
			break;
		}
		case 2 :
		{
			if (idzDo == 0)
			{
				idzDo = new Szlak(postac, this);
			}
			idzDo->start();
			break;
		}
		case 3 :
		{
			if (przybytoZ != 0) 
			{
				przebywaszWWiosce = false;
			}
		}
	}
}



void Wioska::logo()
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, 240);
	//100 x 12
	string wynik = "";
	wynik += "@@@@@            @@@                               @@@@@@               @             @@@@@@@       ";
	wynik += "@ @@          @@@  @@ @@@@@@@                 @@@@@@@@@@@@@@@@@      @@@@@         @@@@@@@@@@@@@@@@@";
	wynik += "@@@            @@@@@@@@@@@@                  @@@@@@@@@    @@  @                   @@@     @@@@@@@@@ ";
	wynik += "                  @                                      @                                          ";
	wynik += "                                                                                                    ";
	wynik += "                                                                                                    ";
	wynik += "                                   %%%%                                                             ";
	wynik += "                                 %%%%%%%%                                                           ";
	wynik += "                  ^^^^^           %%%%%%              ^^^^^^^               ^^^^^^^                 ";
	wynik += "                 ^_____^            ##               ^KARCZMA^             ^_______^                ";
	wynik += "                 ## ## #            ##               # ##^^# #             #  #  # #                ";
	wynik += "                 #######            ##               ####  ###             #  #  # #                ";
	wynik += "----------------------------------------------------------------------------------------------------";
	cout << wynik << endl;
	SetConsoleTextAttribute(hOut, 15);
}
