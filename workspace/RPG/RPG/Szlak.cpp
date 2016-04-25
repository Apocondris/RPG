#include "Szlak.h"


string Szlak::nazwySzlakow[iloscNazwSzlakow];

Szlak::Szlak()
{
	if (czyNazwyLokalizacjiSaPuste(nazwySzlakow, iloscNazwSzlakow))
	{
		ladujNazwyLokalizacji("NazwySzlakow.txt", nazwySzlakow, iloscNazwSzlakow);
	}
	this->nazwa = pobierzNazwe(nazwySzlakow, iloscNazwSzlakow);
	// losowanie 2/3 potworow wystepujacych w tej lokalizacji
}

Szlak::Szlak(Postac * postac):Lokalizacja(postac)
{
	if (czyNazwyLokalizacjiSaPuste(nazwySzlakow, iloscNazwSzlakow))
	{
		ladujNazwyLokalizacji("NazwySzlakow.txt", nazwySzlakow, iloscNazwSzlakow);
	}
	this->nazwa = pobierzNazwe(nazwySzlakow, iloscNazwSzlakow);
	// losowanie 2/3 potworow wystepujacych w tej lokalizacji
}

Szlak::Szlak(Postac * postac, Lokalizacja * lokalizacja) : Lokalizacja(postac, lokalizacja)
{
	if (czyNazwyLokalizacjiSaPuste(nazwySzlakow, iloscNazwSzlakow))
	{
		ladujNazwyLokalizacji("NazwySzlakow.txt", nazwySzlakow, iloscNazwSzlakow);
	}
	this->nazwa = pobierzNazwe(nazwySzlakow, iloscNazwSzlakow);
	// losowanie 2/3 potworow wystepujacych w tej lokalizacji
}


Szlak::~Szlak()
{
}

void Szlak::start()
{
	bool przebywaszNaSzlaku = true;

	while (przebywaszNaSzlaku)
	{
		czyscEkran();
		cout << logo();
		menuGlowne(przebywaszNaSzlaku);
	}
}

void Szlak::menuGlowne(bool &przebywaszNaSzlaku)
{
	short wybor;
	cout << "Znajdujesz sie w wiosce " << this->nazwa << ".." << endl
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
		poluj(postac);
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

void Szlak::poluj(Postac *)
{
	//lowowanie przeciwnika z 3 dostepnych
	//walka z przeciwnikiem
}

Lokalizacja * Szlak::losujLokalizacje(Postac *)
{
	int losowaLiczba = rand() % 1; //po % podaæ liczbê dostêpnych lokalizacji
	switch (losowaLiczba)
	{
	case 0:
	{
		return new Wioska(postac, this);
		break;
	}
	default:
	{
		return new Lokalizacja(postac, this);
		break;
	}
	}
}

string Szlak::logo(void)
{
	//100 x 12
	string wynik = "";
	wynik += "####################################################################################################";
	wynik += "####################################################################################################";
	wynik += "####################################################################################################";
	wynik += "####################################################################################################";
	wynik += "####################################################################################################";
	wynik += "####################################################################################################";
	wynik += "####################################################################################################";
	wynik += "####################################################################################################";
	wynik += "####################################################################################################";
	wynik += "####################################################################################################";
	wynik += "####################################################################################################";
	wynik += "####################################################################################################\n";
	return wynik;
}
