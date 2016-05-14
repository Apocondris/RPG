#include "Bagna.h"
#include "Szlak.h"
#include "Postac.h"
#include "Utopiec.h"
#include <Windows.h>
#include "Walka.h"
#include "Postac.h"
#include "Quest.h"


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

Bagna::~Bagna()
{
	if (przeciwnik != 0)
	{
		delete przeciwnik;
	}
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
	//walka z utopcem
	Walka walka(postac, przeciwnik, 20);
	int wynik = walka.start();
	switch (wynik)
	{
	case 1:
	{
		cout << "Walke wygral " << przeciwnik->nazwa << endl
			<< "W taki oto sposob twoja postac dokonala zywota...";
		system("pause");
		exit(0);
		break;
	}
	case 2:
	{
		cout << "Walke wygral " << postac->imie << endl;
		postac->przydzielDoswiadczenie(przeciwnik->doswiadczenie);
		if (postac->quest != 0)
		{
			string lup = przeciwnik->losuj_lup();
			if (postac->quest->nazwaKlucza == przeciwnik->nazwa)
			{
				if (postac->quest->aktualnaIlosc < postac->quest->ilosc) postac->quest->aktualnaIlosc++;
				cout << "Pokonales przeciwnika na ktorego masz zlecenie. Do wykonania zlecenia pozostalo: " << postac->quest->ilosc - postac->quest->aktualnaIlosc << endl;
			}
			else if (lup != "Brak lupu")
			{
				postac->przedmiotyDoQuestow[lup] ++;
			}

			delete this->przeciwnik;
			this->przeciwnik = new Utopiec();
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
