#include "Kupiec.h"
#include "Postac.h"
#include <Windows.h>

string Kupiec::listaImion[iloscImion];
string Kupiec::listaPowitan[iloscPowitan];

Kupiec::Kupiec(Postac * postac) : Npc(postac)
{
	if (czyListaJestPusta(iloscImion, listaImion))
	{
		ladujDaneNpc("imionaKupcow.txt", listaImion, iloscImion);
	}
	this->imie = pobierzInformacje(iloscImion, listaImion);

	if (czyListaJestPusta(iloscPowitan, listaPowitan))
	{
		ladujDaneNpc("powitaniaKupcow.txt", listaPowitan, iloscPowitan);
	}
	this->powitanie = pobierzInformacje(iloscPowitan, listaPowitan);
}

void Kupiec::start(void)
{
	bool przebywaszUKupca = true;

	while (przebywaszUKupca)
	{
		czyscEkran();
		logo();
		menuGlowne(przebywaszUKupca);
	}
}

void Kupiec::menuGlowne(bool & przebywaszUKupca)
{
	short wybor;
	cout << "Przybyles do kupca. " << endl << endl
		<< this->powitanie << endl
		<< "Co chcesz zrobic?" << endl
		<< "1) Zapytaj o imie." << endl
		<< "2) Kup przedmiot." << endl
		<< "3) Sprzedaj przedmiot." << endl
		<< "4) Wyjdz ze sklepu" << endl;
	//if (warunek) cout << "6) cos" << endl;
	cin >> wybor;
	if (cin.fail()) { cout << "Nie jestes zbyt rozgarniety, prawda?" << endl; cin.clear(); }
	cin.ignore(100000, '\n');

	switch (wybor)
	{
		case 1:
		{
			if (zapytanoOImie)
			{
				cout << postac->imie << ": Jak masz na imie?" << endl
					<< imie << ": Juz nie pamietasz? Mam na imie " << imie << endl;
			}
			else
			{
				cout << postac->imie << ": Jak masz na imie?" << endl
					<< "Kupiec: Mam na imie " << imie << endl;
				zapytanoOImie = true;
			}

			getchar();
			break;
		}
		case 2:
		{
			if (zapytanoOImie)
			{
				cout << postac->imie << ": Co masz na sprzedaz?" << endl
					<< imie << ": Oto co mam na sprzedarz .. " << endl;
				// TODO lista przedmiotow do kupienia
			}
			else
			{
				cout << postac->imie << ": Co masz na sprzedaz?" << endl
					<< "Kupiec: Oto co mam na sprzedarz .. " << endl;
				// TODO lista przedmiotow do kupienia
			}

			getchar();
			break;
		}
		case 3:
		{
			cout << postac->imie << ": Chcialbym sprzedac pare rzeczy.." << endl;
			// TODO lista przedmiotow na sprzedaz
			getchar();
			break;
		}
		case 4:
		{
			if (zapytanoOImie)
			{
				cout << postac->imie << ": Do zobaczenia " << imie << endl
					<< imie << " : Do zobaczenia " << endl;
			}
			else
			{
				cout << postac->imie << ": Do zobaczenia" << endl
					<< "Kupiec: Do zobaczenia " << endl;
			}

			przebywaszUKupca = false;
			getchar();
			break;
		}
	}
}

void Kupiec::logo()
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
