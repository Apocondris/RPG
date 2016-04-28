#include "Karczmarz.h"
#include "Postac.h"
#include <Windows.h>

string Karczmarz::listaImion[iloscImion];
string Karczmarz::listaPowitan[iloscPowitan];
string Karczmarz::listaLokalnychPlotek[iloscLokalnychPlotek];
string Karczmarz::listaRad[iloscRad];


Karczmarz::Karczmarz(Postac * postac) : Npc(postac)
{
	if (czyListaJestPusta(iloscImion, listaImion))
	{
		ladujDaneNpc("imionaKarczmarzy.txt", listaImion, iloscImion);
	}
	this->imie = pobierzInformacje(iloscImion, listaImion);

	if (czyListaJestPusta(iloscPowitan, listaPowitan))
	{
		ladujDaneNpc("powitaniaKarczmarzy.txt", listaPowitan, iloscPowitan);
	}
	this->powitanie = pobierzInformacje(iloscPowitan, listaPowitan);

	if (czyListaJestPusta(iloscLokalnychPlotek, listaLokalnychPlotek))
	{
		ladujDaneNpc("lokalnePlotkiKarczmarz.txt", listaLokalnychPlotek, iloscLokalnychPlotek);
	}
	this->lokalnaPlotka = pobierzInformacje(iloscLokalnychPlotek, listaLokalnychPlotek);

	if (czyListaJestPusta(iloscRad, listaRad))
	{
		ladujDaneNpc("radyKarczmarz.txt", listaRad, iloscRad);
	}
}

void Karczmarz::start(void)
{
	bool przebywaszUKarczmarza = true;

	while (przebywaszUKarczmarza)
	{
		czyscEkran();
		logo();
		menuGlowne(przebywaszUKarczmarza);
	}
}

void Karczmarz::menuGlowne(bool &przebywaszUKarczmarza)
{
	short wybor;
	cout << "Podszedles do karczmarza. " << endl << endl
		<< this->powitanie << endl
		<< "Co chcesz zrobic?" << endl
		<< "1) Zapytaj o imie." << endl
		<< "2) Zapytaj o plotki." << endl
		<< "3) Zapytaj o rade." << endl
		<< "4) Zapytaj o cechy." << endl
		<< "5) Zapytaj o posil sie(cena: -)." << endl
		<< "6) Zapytaj o wypocznik(cena: -)." << endl
		<< "7) Odejdz od lady" << endl;
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
					<< imie <<": Juz nie pamietasz? Mam na imie " << imie << endl;
			}
			else 
			{
				cout << postac->imie << ": Jak masz na imie?" << endl
					<< "Karczmarz: Mam na imie " << imie << endl;
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
				cout << postac->imie << ": Cos sie ostatnio dzialo ciekawego?" << endl
					<< imie << ": " << lokalnaPlotka << endl;
			}
			else
			{
				cout << postac->imie << ": Cos sie ostatnio dzialo ciekawego?" << endl
					<< "Karczmarz: " << lokalnaPlotka << endl;
			}

			system("pause");
			//getchar();
			break;
		}
		case 3:
		{
			int losowaLiczba = rand() % iloscRad;
			if (zapytanoOImie)
			{
				cout << postac->imie << ": Masz dla mnie jakies rady?" << endl
					<< imie << ": " << listaRad[losowaLiczba] << endl;
			}
			else
			{
				cout << postac->imie << ": Masz dla mnie jakies rady?" << endl
					<< "Karczmarz: " << listaRad[losowaLiczba] << endl;
			}

			system("pause");
			//getchar();
			break;
		}
		case 4:
		{
			//do skończenia
			if (zapytanoOImie)
			{
				cout << postac->imie << ": Powiedz mi cos o cechach." << endl
					<< imie << ": Cecha A odpowiada za cos." << endl
					<< "Cecha B odpowiada za cos innego" << endl;
			}
			else
			{
				cout << postac->imie << ": Powiedz mi cos o cechach." << endl
					<< "Karczmarz: Cecha A odpowiada za cos." << endl
					<< "Cecha B odpowiada za cos innego" << endl;
			}

			system("pause");
			//getchar();
			break;
		}
		case 5:
		{
			//do skończenia
			if (zapytanoOImie)
			{
				cout << postac->imie << ": Chcialbym cos zjesc." << endl
					<< imie << ": Prosze.. " << endl;
			}
			else
			{
				cout << postac->imie << ": Chcialbym cos zjesc." << endl
					<< "Karczmarz: Prosze.. " << endl;
			}

			system("pause");
			//getchar();
			break;
		}
		case 6:
		{
			//do skończenia
			if (zapytanoOImie)
			{
				cout << postac->imie << ": Chcialbym odpoczac." << endl
					<< imie << ": Tu masz klucz, twoj pokoj jest na gorze." << endl;
			}
			else
			{
				cout << postac->imie << ": Chcialbym odpoczac." << endl
					<< "Karczmarz: Tu masz klucz, twoj pokoj jest na gorze." << endl;
			}

			system("pause");
			//getchar();
			break;
		}
		case 7:
		{
			if (zapytanoOImie)
			{
				cout << postac->imie << ": Do zobaczenia " << imie << endl
					<< imie << " : Do zobaczenia " << endl;
			}
			else
			{
				cout << postac->imie << ": Do zobaczenia" << endl
					<< "Karczmarz: Do zobaczenia " << endl;
			}

			system("pause");
			//getchar();
			przebywaszUKarczmarza = false;
			break;
		}
	}
}



void Karczmarz::logo()
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
