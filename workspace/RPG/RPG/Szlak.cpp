#include "Szlak.h"
#include "Wioska.h"
#include "Bagna.h"
#include "Miasto.h"
#include "Postac.h"
#include <Windows.h>
#include "BandytaLucznik.h"
#include "BandytaWojownik.h"
#include "Dzik.h"
#include "Wilk.h"
#include "Walka.h"
#include "Niedzwiedz.h"
#include "Quest.h"
#include "QuestPolowania.h"
#include "QuestPrzedmiotow.h"
#include <ctime>


string Szlak::nazwySzlakow[iloscNazwSzlakow];

Szlak::Szlak(shared_ptr<Postac> postac, shared_ptr<Lokalizacja> lokalizacja) : Lokalizacja(postac, lokalizacja)
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
	cout << "Znajdujesz sie na szlaku " << this->nazwa << ".." << endl
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
		poluj();
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

void Szlak::poluj()
{
	srand(time(NULL));
	czyscEkran();
	int losowaLiczba = rand() % iloscPrzeciwnikow;
	//cout << "Walczysz z " << tablicaPrzeciwnikow[losowaLiczba]->nazwa << endl;
	//system("pause");
	Walka walka(postac, tablicaPrzeciwnikow[losowaLiczba],20);
	int wynik=walka.start();
	switch (wynik)
	{
		case 1:
		{
				  cout << "Walke wygral " << tablicaPrzeciwnikow[losowaLiczba]->nazwa<<endl
					  << "W taki oto sposob twoja postac dokonala zywota...";
				  system("pause");
				  exit(0);
				  break;
		}
		case 2:
		{
				  cout << "Walke wygral " << postac->imie<<endl;
				  postac->przydzielDoswiadczenie(tablicaPrzeciwnikow[losowaLiczba]->doswiadczenie);
				  if (postac->quest != 0)
				  {
					  string lup = tablicaPrzeciwnikow[losowaLiczba]->losuj_lup();
					  if (postac->quest->nazwaKlucza == tablicaPrzeciwnikow[losowaLiczba]->nazwa)
					  {
						  if (postac->quest->aktualnaIlosc < postac->quest->ilosc) postac->quest->aktualnaIlosc++;
						  cout << "Pokonales przeciwnika na ktorego masz zlecenie. Do wykonania zlecenia pozostalo: " << postac->quest->ilosc - postac->quest->aktualnaIlosc << endl;
					  }
					  else if (lup != "Brak lupu")
					  {
						  postac->przedmiotyDoQuestow[lup] ++;
					  }

					  odswiezPrzeciwnika(losowaLiczba);
				  }
				  break;
		}
		case 3:
		{
				  cout << "Bohater uciekl z pola bitwy!" << endl;
				  break;
		}
	}
	//walka z przeciwnikiem
	system("pause");
}

shared_ptr<Lokalizacja> Szlak::losujLokalizacje(shared_ptr<Postac> postac)
{
	srand(time(NULL));
	int losowaLiczba = rand() % 3; //po % poda� liczb� dost�pnych lokalizacji
	switch (losowaLiczba)
	{
		case 0:
		{
			return make_shared<Wioska>(postac, shared_ptr<Szlak>(this));
			break;
		}
		case 1:
		{
			return make_shared<Bagna>(postac, shared_ptr<Szlak>(this));
			break;
		}
		case 2:
		{
			return make_shared<Miasto>(postac, shared_ptr<Szlak>(this));
			break;
		}
	}
}

shared_ptr<Przeciwnik>Szlak::losujPrzeciwnika(void)
{
	
	//cout << "Losowanie przeciwnikow:" << endl;
	for (int i = 0; i < iloscPrzeciwnikow; i++)
	{
		int losowaLiczba = rand() % 5; //po % poda� liczb� dost�pnych przeciwnikow
		switch (losowaLiczba)
		{
			case 0:
			{
				return make_shared<BandytaLucznik>();
				//cout << "wylosowano bandyte lucznika" << endl;
				break;
			}
			case 1:
			{
				return make_shared<BandytaWojownik>();
				//cout << "wylosowano bandyte wojownika" << endl;
				break;
			}
			case 2:
			{
				return make_shared<Wilk>();
				//cout << "wylosowano wilka" << endl;
				break;
			}
			case 3:
			{
				return make_shared<Dzik>();
				//cout << "wylosowano dzika" << endl;
				break;
			}
			case 4:
			{
				return make_shared<Niedzwiedz>();
				//cout << "wylosowano niedzwiedzia" << endl;
				break;
			}
		}
	}
}

void Szlak::losujPrzeciwnikow(shared_ptr<Przeciwnik> tablica[iloscPrzeciwnikow])
{
	srand(time(NULL));
	//cout << "Losowanie przeciwnikow:" << endl;
	for (int i = 0; i < iloscPrzeciwnikow; i++)
	{
		int losowaLiczba = rand() % 5; //po % poda� liczb� dost�pnych przeciwnikow
		switch (losowaLiczba)
		{
			case 0:
			{
				tablica[i] = make_shared<BandytaLucznik>();
				//cout << "wylosowano bandyte lucznika" << endl;
				break;
			}
			case 1:
			{
				tablica[i] = make_shared<BandytaWojownik>();
				//cout << "wylosowano bandyte wojownika" << endl;
				break;
			}
			case 2:
			{
				tablica[i] = make_shared<Wilk>();
				//cout << "wylosowano wilka" << endl;
				break;
			}
			case 3:
			{
				tablica[i] = make_shared<Dzik>();
				//cout << "wylosowano dzika" << endl;
				break;
			}
			case 4:
			{
				tablica[i] = make_shared<Niedzwiedz>();
				//cout << "wylosowano niedzwiedzia" << endl;
				break;
			}
			default:
			{

				break;
			}
		}
	}
	//system("pause");
}

void Szlak::odswiezPrzeciwnika(short losowaLiczba)
{
	if (tablicaPrzeciwnikow[losowaLiczba]->nazwa == "Wilk") tablicaPrzeciwnikow[losowaLiczba] = make_shared<Wilk>();
	else if (tablicaPrzeciwnikow[losowaLiczba]->nazwa == "Dzik") tablicaPrzeciwnikow[losowaLiczba] = make_shared<Dzik>();
	else if (tablicaPrzeciwnikow[losowaLiczba]->nazwa == "Niedzwiedz") tablicaPrzeciwnikow[losowaLiczba] = make_shared<Niedzwiedz>();
	else if (tablicaPrzeciwnikow[losowaLiczba]->nazwa == "Bandyta Wojownik") tablicaPrzeciwnikow[losowaLiczba] = make_shared<BandytaWojownik>();
	else if (tablicaPrzeciwnikow[losowaLiczba]->nazwa == "Bandyta Lucznik") tablicaPrzeciwnikow[losowaLiczba] = make_shared<BandytaLucznik>();
	else  tablicaPrzeciwnikow[losowaLiczba] = make_shared<Wilk>();
	
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
