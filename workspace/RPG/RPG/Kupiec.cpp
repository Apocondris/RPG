#include "Kupiec.h"
#include "Postac.h"
#include <Windows.h>

string Kupiec::listaImion[iloscImion];
string Kupiec::listaPowitan[iloscPowitan];

Kupiec::Kupiec(shared_ptr<Postac> postac) : Npc(postac)
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

			system("pause");
			//getchar();
			break;
		}
		case 2:
		{
			if (zapytanoOImie)
			{
				cout << postac->imie << ": Co masz na sprzedaz?" << endl
					<< imie << ": Oto co mam na sprzedarz .. " << endl;
				system("pause");
				kupowanie();
			}
			else
			{
				cout << postac->imie << ": Co masz na sprzedaz?" << endl
					<< "Kupiec: Oto co mam na sprzedarz .. " << endl;
				system("pause");
				kupowanie();
			}

			//getchar();
			break;
		}
		case 3:
		{
			cout << postac->imie << ": Chcialbym sprzedac pare rzeczy.." << endl;
			system("pause");
			sprzedaz();
			//getchar();
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
			system("pause");
			//getchar();
			break;
		}
	}
}

void Kupiec::kupowanie(void)
{
	bool kupujesz = true;

	while (kupujesz)
	{
		czyscEkran();
		logo();
		menuKupowania(kupujesz);
	}
}

void Kupiec::menuKupowania(bool & kupujesz)
{
	short wybor;
	cout<< "Co chcesz kupic?" << endl
		<< "1) Kup strzaly. (aktualnie: " << postac->strzaly << " strzal)" << endl
		<< "2) Powrot." << endl;
	//if (warunek) cout << "6) cos" << endl;
	cin >> wybor;
	if (cin.fail()) { cout << "Nie jestes zbyt rozgarniety, prawda?" << endl; cin.clear(); }
	cin.ignore(100000, '\n');

	switch (wybor)
	{
		case 1:
		{
			if (postac->posiadaneZloto >= 5)
			{
				if (zapytanoOImie)
				{
					cout << imie << ": Prosze, oto twoje straly.." << endl;
					postac->strzaly += 10;
					postac->posiadaneZloto -= 5;
				}
				else
				{
					cout << "Kupiec: Prosze, oto twoje straly.." << endl;
					postac->strzaly += 10;
					postac->posiadaneZloto -= 5;
				}
			}
			else
			{
				if (zapytanoOImie)
				{
					cout << imie << ": Nie stac Cie na strzaly." << endl;
				}
				else
				{
					cout << "Kupiec: Nie stac Cie na strzaly." << endl;
				}
			}

			system("pause");
			break;
		}
		case 2:
		{
			kupujesz = false;
			break;
		}
	}
}

void Kupiec::sprzedaz(void)
{
	bool sprzedajesz = true;

	//tymczasowe
	cout << "Nie masz nic na sprzedaz" << endl;
	sprzedajesz = false;
	// -----

	while (sprzedajesz)
	{
		czyscEkran();
		logo();
		menuSprzedazy(sprzedajesz);
	}
}

void Kupiec::menuSprzedazy(bool & sprzedajesz)
{
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
