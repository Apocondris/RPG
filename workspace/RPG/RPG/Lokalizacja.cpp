#include "Lokalizacja.h"



Lokalizacja::Lokalizacja()
{
	postac = new Postac;
	this->przybytoZ = 0;
	this->idzDo = 0;
}

Lokalizacja::Lokalizacja(Postac * postac)
{
	this->postac = postac;
	this->przybytoZ = 0;
	this->idzDo = 0;
}

Lokalizacja::Lokalizacja(Postac *, Lokalizacja * lokalizacja)
{
	this->postac = postac;
	this->przybytoZ = lokalizacja;
	this->idzDo = 0;
}


Lokalizacja::~Lokalizacja()
{
}

void Lokalizacja::start(void)
{
	czyscEkran();
	cout << "Lokalizacja testowa";
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
		menuKarczmy(czyWKarczmie);
	}
}

void Lokalizacja::menuKarczmy(bool &czyWKarczmie)
{
	short wybor;
	cout << "Znajdujesz siê w karczmie" << endl
		<< "Co chcesz zrobic?" << endl
		<< "1) Idz do karczmarza" << endl
		<< "2) Wyjdz z karczmy" << endl
		<< "3) Wyjdz z gry" << endl;
	cin >> wybor;
	cin.ignore(100000, '\n');

	switch (wybor)
	{
		case 1:
		{
			//akcja dla karczmarza
			break;
		}
		case 2:
		{
			czyWKarczmie = false;
			break;
		}
		case 3:
		{
			exit(0);
			break;
		}
	}
}



