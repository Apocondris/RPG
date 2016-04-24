#include "Karczmarz.h"



string Karczmarz::listaImion[iloscImion];
string Karczmarz::listaPowitan[iloscPowitan];

Karczmarz::Karczmarz():Npc()
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
}

Karczmarz::Karczmarz(Postac * postac):Npc(postac)
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
}


Karczmarz::~Karczmarz()
{
}

void Karczmarz::start(void)
{
	bool przebywaszUKarczmarza = true;

	//czyscEkran();
	//cout << "Przybyles do wioski "<< this->nazwa << ".." << endl;
	//system("pause");

	while (przebywaszUKarczmarza)
	{
		czyscEkran();
		cout << logo();
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
		<< "2) Zapytaj o imie." << endl
		<< "3) Zapytaj o imie." << endl
		<< "4) Zapytaj o imie." << endl
		<< "5) Odejdz od lady" << endl;
	//if (warunek) cout << "6) cos" << endl;
	cin >> wybor;
	if (cin.fail()) { cout << "Nie jestes zbyt rozgarniety, prawda?" << endl; cin.clear(); }
	cin.ignore(100000, '\n');

	switch (wybor)
	{
	case 1:
	{
		if (zapotanoOImie)
		{
			cout << postac->imie << ": Jak masz na imie?" << endl
				<< imie <<" : Juz nie pamietasz? Mam na imie " << imie << endl;
		}
		else 
		{
			cout << postac->imie << ": Jak masz na imie?" << endl
				<< "Karczmarz: Mam na imie " << imie << endl;
			zapotanoOImie = true;
		}

		getchar();
		break;
	}
	case 2:
	{
		if (zapotanoOImie)
		{
			cout << postac->imie << ": Jak masz na imie?" << endl
				<< imie << " : Juz nie pamietasz? Mam na imie " << imie << endl;
		}
		else
		{
			cout << postac->imie << ": Jak masz na imie?" << endl
				<< "Karczmarz: Mam na imie " << imie << endl;
			zapotanoOImie = true;
		}

		getchar();
		break;
	}
	case 3:
	{
		if (zapotanoOImie)
		{
			cout << postac->imie << ": Jak masz na imie?" << endl
				<< imie << " : Juz nie pamietasz? Mam na imie " << imie << endl;
		}
		else
		{
			cout << postac->imie << ": Jak masz na imie?" << endl
				<< "Karczmarz: Mam na imie " << imie << endl;
			zapotanoOImie = true;
		}

		getchar();
		break;
	}
	case 4:
	{
		if (zapotanoOImie)
		{
			cout << postac->imie << ": Jak masz na imie?" << endl
				<< imie << " : Juz nie pamietasz? Mam na imie " << imie << endl;
		}
		else
		{
			cout << postac->imie << ": Jak masz na imie?" << endl
				<< "Karczmarz: Mam na imie " << imie << endl;
			zapotanoOImie = true;
		}

		getchar();
		break;
	}
	case 5:
	{
		if (zapotanoOImie)
		{
			cout << postac->imie << ": Do zobaczenia " << imie << endl
				<< imie << " : Do zobaczenia " << endl;
		}
		else
		{
			cout << postac->imie << ": Do zobaczenia" << endl
				<< "Karczmarz: Do zobaczenia " << endl;
		}

		getchar();
		przebywaszUKarczmarza = false;
		break;
	}
	}
}



string Karczmarz::logo()
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
