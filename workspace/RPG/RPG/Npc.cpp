#include "Npc.h"

string Npc::listaImion[iloscImion];
string Npc::listaPowitan[iloscPowitan];

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

void Npc::start(Postac *)
{
	czyscEkran();
	cout << "Szblon NPC";
}

void Npc::czyscEkran()
{
	system("CLS");
}

bool Npc::czyListaImionJestPusta()
{
	for (int i = 0; i < iloscImion; i++)
	{
		if (listaImion[i] != "")
		{
			return false;
		}
	}
	return true;
}

bool Npc::czyListaPowitanJestPusta()
{
	for (int i = 0; i < iloscPowitan; i++)
	{
		if (listaPowitan[i] != "")
		{
			return false;
		}
	}
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

string Npc::pobierzImie()
{
	int losowaLiczba = rand() % iloscImion;
	string temp;
	while (listaImion[losowaLiczba] == "")
	{
		losowaLiczba = rand() % iloscImion;
	}
	temp = listaImion[losowaLiczba];
	listaImion[losowaLiczba] = "";
	return temp;
}

string Npc::pobierzPowitanie()
{
	int losowaLiczba = rand() % iloscPowitan;
	string temp;
	while (listaPowitan[losowaLiczba] == "")
	{
		losowaLiczba = rand() % iloscPowitan;
	}
	temp = listaPowitan[losowaLiczba];
	listaPowitan[losowaLiczba] = "";
	return temp;
}
