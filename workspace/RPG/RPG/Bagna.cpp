#include "Bagna.h"
#include "Szlak.h"
#include "Postac.h"
#include "Utopiec.h"
#include <Windows.h>


string Bagna::nazwyBagien[iloscNazwBagien];

Bagna::Bagna(Postac * postac, Lokalizacja * lokalizacja) : Lokalizacja(postac, lokalizacja)
{
	if (czyNazwyLokalizacjiSaPuste(nazwyBagien, iloscNazwBagien))
	{
		ladujNazwyLokalizacji("NazwyBagien.txt", nazwyBagien, iloscNazwBagien);
	}
	this->nazwa = pobierzNazwe(nazwyBagien, iloscNazwBagien);
	this->przeciwnik = new Utopiec();
}

void Bagna::start(void)
{
	bool przebywaszNaBagnach = true;

	while (przebywaszNaBagnach)
	{
		czyscEkran();
		logo();
		menuGlowne(przebywaszNaBagnach);
	}
}

void Bagna::menuGlowne(bool & przebywaszNaBagnach)
{
	short wybor;
	cout << "Znajdujesz sie na bagnach " << this->nazwa << ".." << endl
		<< "Co chcesz zrobic?" << endl
		<< "1) poluj" << endl
		<< "2) Podrozuj dalej" << endl
		<< "3) Wroc do poprzedniej lokalizacji" << endl;
	cin >> wybor;
	if (cin.fail()) { cout << "Nie jestes zbyt rozgarniety, prawda?" << endl; cin.clear(); }
	cin.ignore(100000, '\n');

	switch (wybor)
	{
	case 1:
	{
		poluj();
		break;
	}
	case 2:
	{
		if (idzDo == 0)
		{
			idzDo = new Szlak(postac, this);
		}
		idzDo->start();
		break;
	}
	case 3:
	{
		if (przybytoZ != 0)
		{
			przebywaszNaBagnach = false;
		}
	}
	}
}

void Bagna::poluj()
{
	czyscEkran();
	cout << "Walczysz z " << przeciwnik->nazwa << endl;
	system("pause");
	//walka z utopcem
}

void Bagna::logo()
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
