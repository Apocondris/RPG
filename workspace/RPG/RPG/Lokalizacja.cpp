#include "Lokalizacja.h"
#include "Szlak.h"
#include "Wioska.h"
#include "Bagna.h"
#include "Miasto.h"
#include "Karczmarz.h"
#include "Postac.h"
#include "Przedmiot.h"
#include "Bron.h"
#include "Pancerz.h"
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
#include "QuestPrzedmiotow.h"


Lokalizacja::Lokalizacja(shared_ptr<Postac> postac)
{
	this->postac = postac;
	this->przybytoZ = 0;
	this->idzDo = 0;
	this->karczmarz = 0;
}

Lokalizacja::Lokalizacja(shared_ptr<Postac> postac, shared_ptr<Lokalizacja> lokalizacja)
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
	if (postac->punktyDoWydania > 0) cout << "6) Rozdaj punkty rozwoju postaci" << endl;
	cin >> wybor;
	if (cin.fail()) { cout << "Nie jestes zbyt rozgarniety, prawda?" << endl; cin.clear(); }
	cin.ignore(100000, '\n');

	switch (wybor)
	{
		case 1:
		{
			if (karczmarz == 0)	karczmarz = make_unique<Karczmarz>(postac);
			karczmarz -> start();
			break;
		}
		case 2:
		{
			tablicaOgloszen();
			break;
		}
		case 3:
		{
			przegladajEkwipunek();
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
		case 6:
		{
			rozdanieExpa();
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

void Lokalizacja::przegladajEkwipunek(void)
{
	bool czyPrzegladaszEkwipunek = true;
	while (czyPrzegladaszEkwipunek)
	{
		czyscEkran();
		//logoKarczmy();
		postac->wyswietlEkwipunek();
		menuPrzegladaniaEkwipunku(czyPrzegladaszEkwipunek);
	}

}

void Lokalizacja::menuPrzegladaniaEkwipunku(bool & czyPrzegladaszEkwipunek)
{
	short wybor;
	cout << "Co chcesz zrobic?" << endl
		<< "1) zdejmij przedmiot" << endl
		<< "2) zaloz przedmiot" << endl
		<< "3) powrot" << endl;

	cin >> wybor;
	if (cin.fail()) { cout << "Nie jestes zbyt rozgarniety, prawda?" << endl; cin.clear(); }
	cin.ignore(100000, '\n');

	switch (wybor)
	{
		case 1:
		{
			bool czyZdejmujeszEkwipunek = true;
			while (czyZdejmujeszEkwipunek)
			{
				czyscEkran();
				postac->wyswietlEkwipunek();
				menuZdejmowaniaEkwipunku(czyZdejmujeszEkwipunek);
				system("pause");
			}
			break;
		}
		case 2:
		{
			bool czyZakladaszEkwipunek = true;
			while (czyZakladaszEkwipunek)
			{
				czyscEkran();
				menuZakladaniaEkwipunku(czyZakladaszEkwipunek);
				system("pause");
			}
			break;
		}
		case 3:
		{
			czyPrzegladaszEkwipunek = false;
			break;
		}
	}
	//TODO przegladanie ekwipunku
}

void Lokalizacja::menuZdejmowaniaEkwipunku(bool & czyZdejmujeszEkwipunek)
{
	short wybor;
	cout << "Co chcesz zrobic?" << endl
		<< "1) schowaj bron do plecaka" << endl
		<< "2) zdejmij pancerz i schowaj do plecaka" << endl
		<< "3) powrot" << endl;

	cin >> wybor;
	if (cin.fail()) { cout << "Nie jestes zbyt rozgarniety, prawda?" << endl; cin.clear(); }
	cin.ignore(100000, '\n');

	switch (wybor)
	{
		case 1:
		{
			bool zdjeto = false;
			if (postac->bron != 0)
			{
				for (int i = 0; i < postac->wielkoscEkwipunku && !zdjeto; i++)
				{
					if (postac->ekwipunek[i] == 0)
					{
						postac->ekwipunek[i] = postac->bron;
						postac->bron = 0;
						zdjeto = true;
					}
				}
				if (zdjeto) cout << "Przedmiot zostal umieszczony w twoim plecaku" << endl;
				else cout << "Przedmiot nie zostal zdjety, poniewaz skonczylo Ci sie miejsce w plecaku" << endl;
			}
			else
			{
				cout << "Nie trzymasz zadnej broni!" << endl;
			}
			break;
		}
		case 2:
		{
			bool zdjeto = false;
			if (postac->pancerz != 0)
			{
				for (int i = 0; i < postac->wielkoscEkwipunku && !zdjeto; i++)
				{
					if (postac->ekwipunek[i] == 0)
					{
						postac->ekwipunek[i] = postac->pancerz;
						postac->pancerz = 0;
						zdjeto = true;
					}
				}
				if (zdjeto) cout << "Przedmiot zostal umieszczony w twoim plecaku" << endl;
				else cout << "Przedmiot nie zostal zdjety, poniewaz skonczylo Ci sie miejsce w plecaku" << endl;
			}
			else
			{
				cout << "Nie masz zalozonego zadnego pancerza!" << endl;
			}
			break;
		}
		case 3:
		{
			czyZdejmujeszEkwipunek = false;
			break;
		}
	}
}

void Lokalizacja::menuZakladaniaEkwipunku(bool & czyZakladaszEkwipunek)
{
	short wybor;

	cout << "Co chcesz zalozyc?" << endl;
	postac->wyswietlNumerowanyPlecak();
	cout << postac->wielkoscEkwipunku+1 << ") powrot" << endl;

	cin >> wybor;
	if (cin.fail()) { cout << "Nie jestes zbyt rozgarniety, prawda?" << endl; cin.clear(); }
	cin.ignore(100000, '\n');

	if(wybor == postac->wielkoscEkwipunku+1)
	{
		czyZakladaszEkwipunek = false;
	}
	else
	{
		postac->zmienPrzedmiot(wybor);
	}
}

void Lokalizacja::rozdanieExpa(void)
{
	bool czyRozdajeszExpa = true;
	while (czyRozdajeszExpa)
	{
		czyscEkran();
		logoKarczmy();
		menuRozdaniaExpa(czyRozdajeszExpa);
	}
}

void Lokalizacja::menuRozdaniaExpa(bool &czyRozdajeszExpa)
{
	short wybor;
	cout << "Na co chcesz wydac swoje punktu?" << endl
		<< "(Pozostalo " << postac->punktyDoWydania << " punktow)" << endl
		<< "1) Atak - aktualenie " << postac->atak << "pkt" << endl
		<< "2) Obrona - aktualenie " << postac->obrona << "pkt" << endl
		<< "3) Szybkosc - aktualenie " << postac->szybkosc << "pkt" << endl
		<< "4) Szczescie - aktualenie " << postac->szczescie << "pkt" << endl
		<< "5) Zdrowie - aktualenie " << postac->max_zdrowie << "pkt" << endl
		<< "6) Wytrzymalosc - aktualenie " << postac->max_wytrzymalosc << "pkt" << endl
		<< "7) Zakoncz wydawanie" << endl;
	cin >> wybor;
	if (cin.fail()) { cout << "Nie jestes zbyt rozgarniety, prawda?" << endl; cin.clear(); }
	cin.ignore(100000, '\n');

	switch (wybor)
	{
		case 1:
		{
			postac->atak += 1;
			postac->punktyDoWydania--;
			break;
		}
		case 2:
		{
			postac->obrona += 1;
			postac->punktyDoWydania--;
			break;
		}
		case 3:
		{
			postac->szybkosc += 1;
			postac->punktyDoWydania--;
			break;
		}
		case 4:
		{
			postac->szczescie += 1;
			postac->punktyDoWydania--;
			break;
		}
		case 5:
		{
			postac->max_zdrowie += 10;
			postac->punktyDoWydania--;
			break;
		}
		case 6:
		{
			postac->max_wytrzymalosc += 2;
			postac->punktyDoWydania--;
			break;
		}
		case 7:
		{
			czyRozdajeszExpa = false;
		}
	}
	if (postac->punktyDoWydania <= 0) czyRozdajeszExpa = false;
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
