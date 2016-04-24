#include "Npc.h"

Npc::Npc()
{
	this->postac = new Postac();
}

Npc::Npc(Postac * postac) 
{
	this->postac = postac;
}


Npc::~Npc()
{
}

void Npc::start()
{
	czyscEkran();
	cout << "Szblon NPC";
}

void Npc::czyscEkran()
{
	system("CLS");
}

bool Npc::czyListaJestPusta(int iloscElementow, string * lista)
{
	for (int i = 0; i < iloscElementow; i++)
	{
		if (lista[i] != "")
		{
			return false;
		}
	}
	return true;
}

void Npc::ladujDaneNpc(string sciezka, string * tablica, const int iloscDanych)
{
	ifstream strumienWejsciowy;
	strumienWejsciowy.open(sciezka);
	if (strumienWejsciowy.good())
	{
		//cout << endl << "Pobrane nazwy:" << endl;
		for (int i = 0; i < iloscDanych; i++)
		{
			string odczytZPliku;
			getline(strumienWejsciowy, odczytZPliku);
			tablica[i] = odczytZPliku;
			//cout << odczytZPliku << endl;
		}
		//system("pause");
	}
	else
	{
		czyscEkran();
		cout << "Nie udalo sie utworzyc pliku " << sciezka << endl
			<< "Nastepuje zamkniecie gry." << endl;
		system("pause");
		exit(-1);
	}
	//system("pause");
}

string Npc::pobierzInformacje(const int liczbaDostepnych, string * listaDanych)
{
	int losowaLiczba = rand() % liczbaDostepnych;
	string temp;
	while (listaDanych[losowaLiczba] == "")
	{
		losowaLiczba = rand() % liczbaDostepnych;
	}
	temp = listaDanych[losowaLiczba];
	listaDanych[losowaLiczba] = "";
	return temp;
}
