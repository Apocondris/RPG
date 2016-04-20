#include "Lokalizacja.h"

string Lokalizacja::nazwyLokalizacji[iloscNazw];

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
		menuKarczmy(czyWKarczmie);
	}
}

void Lokalizacja::menuKarczmy(bool &czyWKarczmie)
{
	short wybor;
	cout << "Znajdujesz sie w karczmie" << endl
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

bool Lokalizacja::czyNazwyLokalizacjiSaPuste()
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

void Lokalizacja::ladujNazwyLokalizacji(string sciezka)
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
			this->nazwyLokalizacji[i] = odczytZPliku;
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

string Lokalizacja::pobierzNazwe()
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



