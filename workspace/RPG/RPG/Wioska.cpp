#include "Wioska.h"



string Wioska::nazwyWiosek[iloscNazw];

Wioska::Wioska()
{
	if (czyNazwyLokalizacjiSaPuste())
	{
		ladujNazwyWiosek();
	}
	this->nazwa = pobierzNazwe();
}

Wioska::Wioska(Postac * postac) : Lokalizacja(postac)
{
	if (czyNazwyLokalizacjiSaPuste())
	{
		ladujNazwyWiosek();
	}
	this->nazwa = pobierzNazwe();
}

Wioska::Wioska(Postac * postac, Lokalizacja * lokalizacja) : Lokalizacja(postac, lokalizacja)
{
	if (czyNazwyLokalizacjiSaPuste())
	{
		ladujNazwyWiosek();
	}
	this->nazwa = pobierzNazwe();
}


Wioska::~Wioska()
{
}

void Wioska::start(void)
{
	bool przebywaszWWiosce = true;

	czyscEkran();
	cout << "Przybyles do wioski "<< this->nazwa << ".." << endl;
	system("pause");

	while (przebywaszWWiosce)
	{
		czyscEkran();
		menuGlowne(przebywaszWWiosce);
	}
}

void Wioska::menuGlowne(bool & przebywaszWWiosce)
{
	short wybor;
	cout << "Znajdujesz sie w wiosce " << this->nazwa << ".." << endl
		<< "Co chcesz zrobic?" << endl
		<< "1) Idz do karczmy" << endl
		<< "2) Podrozuj dalej" << endl;
	if (przybytoZ != 0) cout << "3) Wroc do poprzedniej lokalizacji" << endl;
	cin >> wybor;
	cin.ignore(100000, '\n');

	switch (wybor)
	{
		case 1 :
		{
			karczma();
			break;
		}
		case 2 :
		{
			if (idzDo == 0)
			{
				idzDo = losujLokalizacje(postac);
			}
			idzDo->start();
			break;
		}
		case 3 :
		{
			if (przybytoZ != 0) 
			{
				przebywaszWWiosce = false;
			}
		}
	}
}

Lokalizacja * Wioska::losujLokalizacje(Postac *)
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

void Wioska::ladujNazwyWiosek()
{
	ifstream strumienWejsciowy;
	strumienWejsciowy.open("NazwyWiosek.txt");
	if (strumienWejsciowy.good())
	{
		//cout << endl << "Pobrane nazwy:" << endl;
		for (int i = 0; i < iloscNazw; i++)
		{
			string odczytZPliku;
			getline(strumienWejsciowy, odczytZPliku);
			this->nazwyWiosek[i] = odczytZPliku;
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

bool Wioska::czyNazwyLokalizacjiSaPuste()
{
	for (int i = 0; i < iloscNazw; i++)
	{
		if (nazwyWiosek[i] != "")
		{
			return false;
		}
	}
	return true;
}

string Wioska::pobierzNazwe()
{
	int losowaLiczba = rand() % iloscNazw;
	string temp;
	while (nazwyWiosek[losowaLiczba] == "")
	{
		losowaLiczba = rand() % iloscNazw;
	}
	temp = nazwyWiosek[losowaLiczba];
	nazwyWiosek[losowaLiczba] = "";
	return temp;
}


