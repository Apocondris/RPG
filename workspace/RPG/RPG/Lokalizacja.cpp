#include "Lokalizacja.h"
#include "Karczmarz.h"
#include "Postac.h"
#include <Windows.h>
#include "BandytaLucznik.h"
#include "BandytaWojownik.h"
#include "Dzik.h"
#include "Wilk.h"
#include "Niedzwiedz.h"
#include "Utopiec.h"
#include "Quest.h"
#include "QuestFabryka.h"
#include "QuestPolowania.h"


Lokalizacja::Lokalizacja(Postac * postac)
{
	this->postac = postac;
	this->przybytoZ = 0;
	this->idzDo = 0;
	this->karczmarz = 0;
}

Lokalizacja::Lokalizacja(Postac * postac, Lokalizacja * lokalizacja)
{
	this->postac = postac;
	this->przybytoZ = lokalizacja;
	this->idzDo = 0;
	this->karczmarz = 0;
}

void Lokalizacja::start(void)
{
	czyscEkran();
	cout << "Szablon lokalizacji";
}

void Lokalizacja::czyscEkran(void)
{
	system("CLS");
}

void Lokalizacja::karczma(void)
{
	bool czyWKarczmie = true;
	while (czyWKarczmie)
	{
		czyscEkran();
		logoKarczmy();
		menuKarczmy(czyWKarczmie);
	}
}

void Lokalizacja::menuKarczmy(bool &czyWKarczmie)
{
	short wybor;
	cout << "Znajdujesz sie w karczmie" << endl
		<< "Co chcesz zrobic?" << endl
		<< "1) Idz do karczmarza" << endl
		<< "2) Tablica ogloszen" << endl
		<< "3) Przegladaj ekwipunek" << endl
		<< "4) Wyjdz z karczmy" << endl
		<< "5) Wyjdz z gry" << endl;
	cin >> wybor;
	if (cin.fail()) { cout << "Nie jestes zbyt rozgarniety, prawda?" << endl; cin.clear(); }
	cin.ignore(100000, '\n');

	switch (wybor)
	{
		case 1:
		{
			if (karczmarz == 0)	karczmarz = new Karczmarz(postac);
			karczmarz -> start();
			break;
		}
		case 2:
		{
			tablicaOgloszen();
			break;
		}
		case 4:
		{
			czyWKarczmie = false;
			break;
		}
		case 5:
		{
			exit(0);
			break;
		}
	}
}

void Lokalizacja::tablicaOgloszen(void)
{
	bool czyPrzyTablicy = true;
	while (czyPrzyTablicy)
	{
		czyscEkran();
		logoTablicyOgloszen();
		menuTablicyOgloszen(czyPrzyTablicy);
	}
}

void Lokalizacja::menuTablicyOgloszen(bool & czyPrzyTablicy)
{
	short wybor;
	cout << "Znajdujesz sie przy tablicy ogloszen" << endl
		<< "Co chcesz zrobic?" << endl
		<< "1) Szukaj zelecenia" << endl
		<< "2) Odejdz" << endl;
	cin >> wybor;
	if (cin.fail()) { cout << "Nie jestes zbyt rozgarniety, prawda?" << endl; cin.clear(); }
	cin.ignore(100000, '\n');

	switch (wybor)
	{
		case 1:
		{
			if (postac->quest == 0) 
			{
				bool poszukiwania = true;
				while (poszukiwania)
				{
					short opcja;
					postac->quest = QuestFabryka::utworzQuest();
					cout << "Znalazles zlecenie: " << postac->quest->nazwaQuesta << endl
						<< "opis: " << postac->quest->opis << endl
						<< "nagroda: " << postac->quest->nagroda << endl
						<< "Czy przyjmujesz zlecenie?	1) tak	2)nie	" << endl;
					cin >> opcja;
					if (cin.fail()) { cout << "Nie jestes zbyt rozgarniety, prawda?" << endl; cin.clear(); }
					cin.ignore(100000, '\n');
					if (opcja == 1) poszukiwania = false;
				}
			}
			else
			{
				cout << "Juz przyjales zlecenie: " << postac->quest->nazwaQuesta << endl
					<< "opis: " << postac->quest->opis << endl
					<< "nagroda: " << postac->quest->nagroda << endl;
			}
			system("pause");
			break;
		}
		case 2:
		{
			czyPrzyTablicy = false;
			break;
		}
	}
}

bool Lokalizacja::czyNazwyLokalizacjiSaPuste(string * nazwyLokalizacji, int iloscNazw)
{
	for (int i = 0; i < iloscNazw; i++)
	{
		if (nazwyLokalizacji[i] != "")
		{
			return false;
		}
	}
	return true;
}

void Lokalizacja::ladujNazwyLokalizacji(string sciezka, string * nazwyLokalizacji, int iloscNazw)
{
	ifstream strumienWejsciowy;
	strumienWejsciowy.open(sciezka);
	if (strumienWejsciowy.good())
	{
		//cout << endl << "Pobrane nazwy:" << endl;
		for (int i = 0; i < iloscNazw; i++)
		{
			string odczytZPliku;
			getline(strumienWejsciowy, odczytZPliku);
			nazwyLokalizacji[i] = odczytZPliku;
			//cout << odczytZPliku << endl;
		}
	}
	else
	{
		czyscEkran();
		cout << "Nie udalo sie utworzyc pliku z nazwami wiosek." << endl
			<< "Nastepuje zamkniecie gry." << endl;
		system("pause");
		exit(-1);
	}
	//system("pause");
}

string Lokalizacja::pobierzNazwe(string * nazwyLokalizacji, int iloscNazw)
{
	int losowaLiczba = rand() % iloscNazw;
	string temp;
	while (nazwyLokalizacji[losowaLiczba] == "")
	{
		losowaLiczba = rand() % iloscNazw;
	}
	temp = nazwyLokalizacji[losowaLiczba];
	nazwyLokalizacji[losowaLiczba] = "";
	return temp;
}



void Lokalizacja::logoKarczmy()
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

void Lokalizacja::logoTablicyOgloszen()
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
