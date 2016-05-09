#include "Karczmarz.h"
#include "Postac.h"
#include <Windows.h>
#include "Quest.h"
#include "QuestPolowania.h"

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
		<< "5) Zapytaj o posil sie(cena: 3)." << endl
		<< "6) Zapytaj o wypocznik(cena: 15)." << endl
		<< "7) Odejdz od lady" << endl;
	if (postac->quest != 0) cout << "8) Oddaj quest" << endl;
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
			//do skoñczenia
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
			if (postac->posiadaneZloto >= 3)
			{
				if (zapytanoOImie)
				{
					cout << postac->imie << ": Chcialbym cos zjesc." << endl
						<< imie << ": Prosze.. " << endl;
					postac->zdrowie += 20;
					if (postac->zdrowie > postac->getMaxZdrowie()) postac->zdrowie = postac->getMaxZdrowie();
					postac->posiadaneZloto -= 3;
				}
				else
				{
					cout << postac->imie << ": Chcialbym cos zjesc." << endl
						<< "Karczmarz: Prosze.. " << endl;
					postac->zdrowie += 20;
					postac->wytrzymalosc += 20;
					if (postac->zdrowie > postac->getMaxZdrowie()) postac->zdrowie = postac->getMaxZdrowie();
					if (postac->wytrzymalosc > postac->getMaxWytrzymalosc()) postac->wytrzymalosc = postac->getMaxWytrzymalosc();
					postac->posiadaneZloto -= 3;
				}
			}
			else
			{
				if (zapytanoOImie)
				{
					cout << postac->imie << ": Chcialbym cos zjesc." << endl
						<< imie << ": Nie masz czym za to zaplacic. " << endl;
				}
				else
				{
					cout << postac->imie << ": Chcialbym cos zjesc." << endl
						<< "Karczmarz: Nie masz czym za to zaplacic. " << endl;
				}
			}
			

			system("pause");
			//getchar();
			break;
		}
		case 6:
		{
			if (postac->posiadaneZloto >= 15)
			{
				if (zapytanoOImie)
				{
					cout << postac->imie << ": Chcialbym odpoczac." << endl
						<< imie << ": Tu masz klucz, twoj pokoj jest na gorze." << endl;
					postac->zdrowie = postac->getMaxZdrowie();
					postac->wytrzymalosc = postac->getMaxWytrzymalosc();
					postac->posiadaneZloto -= 15;
				}
				else
				{
					cout << postac->imie << ": Chcialbym odpoczac." << endl
						<< "Karczmarz: Tu masz klucz, twoj pokoj jest na gorze." << endl;
					postac->zdrowie = postac->getMaxZdrowie();
					postac->wytrzymalosc = postac->getMaxWytrzymalosc();
					postac->posiadaneZloto -= 15;
				}
			}
			else
			{
				if (zapytanoOImie)
				{
					cout << postac->imie << ": Chcialbym odpoczac." << endl
						<< imie << ": Nie masz czym za to zaplacic. " << endl;
				}
				else
				{
					cout << postac->imie << ": Chcialbym odpoczac." << endl
						<< "Karczmarz: Nie masz czym za to zaplacic. " << endl;
				}
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
		}case 8:
		{
			if (postac->quest != 0)
			{
				if (postac->quest->nazwaQuesta == "Upoluj")
				{
					if (zapytanoOImie)
					{
						if (postac->quest->aktualnaIlosc < postac->quest->ilosc)
						{
							cout << postac->imie << ": Chcialbym odebrac nagrode za zlecenie " << postac->quest->nazwaQuesta << endl
								<< imie << " : Jeszcze nie ukonczyles zlecenia. Musisz jeszcze upolowac " << postac->quest->ilosc - postac->quest->aktualnaIlosc << " " << postac->quest->nazwaKlucza << endl;
						}
						else
						{
							cout << postac->imie << ": Chcialbym odebrac nagrode za zlecenie " << postac->quest->nazwaQuesta << endl
								<< imie << " : Oto zaplata.." << endl;
							postac->posiadaneZloto += postac->quest->nagroda;
							postac->quest = 0;
						}
					}
					else
					{
						if (postac->quest->aktualnaIlosc < postac->quest->ilosc)
						{
							cout << postac->imie << ": Chcialbym odebrac nagrode za zlecenie " << postac->quest->nazwaQuesta << endl
								<< "Karczmarz: Jeszcze nie ukonczyles zlecenia. Musisz jeszcze upolowac " << postac->quest->ilosc - postac->quest->aktualnaIlosc << " " << postac->quest->nazwaKlucza << endl;
						}
						else
						{
							cout << postac->imie << ": Chcialbym odebrac nagrode za zlecenie " << postac->quest->nazwaQuesta << endl
								<< "Karczmarz: Oto zaplata.." << endl;
							postac->posiadaneZloto += postac->quest->nagroda;
							postac->quest = 0;
						}
					}
				}
				else if (postac->quest->nazwaQuesta == "Przynies")
				{
					if (zapytanoOImie)
					{
						if (postac->przedmiotyDoQuestow[postac->quest->nazwaKlucza] < postac->quest->ilosc)
						{
							cout << postac->imie << ": Chcialbym odebrac nagrode za zlecenie " << postac->quest->nazwaQuesta << endl
								<< imie << " : Jeszcze nie ukonczyles zlecenia. Musisz jeszcze zdobyc " << postac->quest->ilosc - postac->przedmiotyDoQuestow[postac->quest->nazwaKlucza] << " " << postac->quest->nazwaKlucza << endl;
						}
						else
						{
							cout << postac->imie << ": Chcialbym odebrac nagrode za zlecenie " << postac->quest->nazwaQuesta << endl
								<< imie << " : Oto zaplata.." << endl;
							postac->przedmiotyDoQuestow[postac->quest->nazwaKlucza] -= postac->quest->ilosc;
							postac->posiadaneZloto += postac->quest->nagroda;
							postac->quest = 0;
						}
					}
					else
					{
						if (postac->przedmiotyDoQuestow[postac->quest->nazwaKlucza] < postac->quest->ilosc)
						{
							cout << postac->imie << ": Chcialbym odebrac nagrode za zlecenie " << postac->quest->nazwaQuesta << endl
								<< "Karczmarz: Jeszcze nie ukonczyles zlecenia. Musisz jeszcze zdobyc " << postac->quest->ilosc - postac->przedmiotyDoQuestow[postac->quest->nazwaKlucza] << " " << postac->quest->nazwaKlucza << endl;
						}
						else
						{
							cout << postac->imie << ": Chcialbym odebrac nagrode za zlecenie " << postac->quest->nazwaQuesta << endl
								<< "Karczmarz: Oto zaplata.." << endl;
							postac->przedmiotyDoQuestow[postac->quest->nazwaKlucza] -= postac->quest->ilosc;
							postac->posiadaneZloto += postac->quest->nagroda;
							postac->quest = 0;
						}
					}
				}

				system("pause");
				//getchar();
			}
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
