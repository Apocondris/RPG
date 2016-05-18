#include "Postac.h"
#include "Bron.h"
#include "Przedmiot.h"
#include "Pancerz.h"
#include "FabrykaWyposazenia.h"

Postac::Postac()
{
	this->imie = "Bezimienny";
}

Postac::Postac(string imie, string klasa, Bron* bron, Pancerz* pancerz)
{
	this->imie = imie;
	this->klasa_postaci = klasa;
	quest = 0;
	this->bron = bron;
	this->pancerz = pancerz;
	pancerz = 0;
	przedmiotyDoQuestow["Skora wilka"] += 10;
	doswiadczenieDoNastepnegoPoziomu = 100;

	for (int i = 0; i < wielkoscEkwipunku; i++)
		ekwipunek[i] = 0;
	this->ekwipunek[0] = FabrykaWyposazenia::generujLuk();
	this->ekwipunek[1] = FabrykaWyposazenia::generujMiecz();
	this->ekwipunek[2] = FabrykaWyposazenia::generujPancerz();
	this->ekwipunek[3] = FabrykaWyposazenia::generujWyposazenie();

}


Postac::~Postac()
{
	if (bron != 0)
	{
		delete bron;
	}
	if (pancerz != 0)
	{
		delete pancerz;
	}
	for (int i = 0; i < wielkoscEkwipunku; i++)
	{
		if (ekwipunek[i] != 0)
		{
			delete ekwipunek[i];
		}
	}
}

void Postac::wyswietlEkwipunek(void)
{
	cout << "EKWIPUNEK:" << endl;
	if (bron != 0)
		cout << "zalozona bron: " << bron->toString() << endl;
	else
		cout << "zalozona bron: brak broni!" << endl;
	if (pancerz != 0)
		cout << "zalozony pancerz: " << pancerz->toString() << endl;
	else
		cout << "zalozony pancerz: brak pancerza!" << endl << endl;
	cout << "RZECZY W PLECAKU:" << endl;
	for (int i = 0; i < wielkoscEkwipunku; i++)
	{
		cout << "=======================================" << endl;
		if (ekwipunek[i] != 0)
		{
			cout << ekwipunek[i]->toString() << endl;
		}
		else
		{
			cout << "puste" << endl;
		}
	}
	cout << "=======================================" << endl;
}

void Postac::wyswietlNumerowanyPlecak(void)
{
	cout << "RZECZY W PLECAKU:" << endl;
	for (int i = 0; i < wielkoscEkwipunku; i++)
	{
		cout << "=======================================" << endl;
		if (ekwipunek[i] != 0)
		{
			cout << i+1 << ") " << ekwipunek[i]->toString() << endl;
		}
		else
		{
			cout << "puste" << endl;
		}
	}
	cout << "=======================================" << endl;
}

void Postac::zmienPrzedmiot(short wybor)
{
	wybor -= 1;
	if (wybor < 0 || wybor >= wielkoscEkwipunku)
	{
		cout << "Podano niepoprawna liczbe!" << endl;
	}
	else
	{
		if (ekwipunek[wybor] != 0)
		{
			if (typeid(*ekwipunek[wybor]) == typeid(Bron))
			{
				if (klasa_postaci == "lucznik" && ekwipunek[wybor]->nazwa == "luk" || klasa_postaci == "wojownik" && ekwipunek[wybor]->nazwa == "miecz")
				{
					if (bron != 0)
					{
						Bron * temp = bron;
						bron = dynamic_cast<Bron*>(ekwipunek[wybor]);
						ekwipunek[wybor] = temp;
					}
					else
					{
						bron = dynamic_cast<Bron*>(ekwipunek[wybor]);
						ekwipunek[wybor] = 0;
					}
				}
				else
				{
					cout << "Jako " << klasa_postaci << " nie mozesz nosic broniu typu " << ekwipunek[wybor]->nazwa << endl;
				}
			}
			else if(typeid(*ekwipunek[wybor]) == typeid(Pancerz))
			{
				if (pancerz != 0)
				{
					Pancerz * temp = pancerz;
					pancerz = dynamic_cast<Pancerz*>(ekwipunek[wybor]);
					ekwipunek[wybor] = temp;
				}
				else
				{
					pancerz = dynamic_cast<Pancerz*>(ekwipunek[wybor]);
					ekwipunek[wybor] = 0;
				}
			}
		}
		else
		{
			cout << "Podales puste miejsce!" << endl;
		}
	}
}

void Postac::dodajPrzedmiotDoEkwipunku(Przedmiot *)
{
}

void Postac::usunPrzedmiotZEkwipunku(unsigned short i)
{
	if (ekwipunek[i] != 0)
	{
		delete ekwipunek[i];
		ekwipunek[i] = 0;
	}
}

void Postac::przydzielDoswiadczenie(unsigned int otrzymaneDoswadczenie)
{
	this->aktualneDoswadczenie += otrzymaneDoswadczenie;
	if (aktualneDoswadczenie >= doswiadczenieDoNastepnegoPoziomu)
	{
		cout << "Zdobyles kolejny poziom. Zdobyte punkty mozesz przydzielic podczas pobytu w karczmie." << endl;
		aktualneDoswadczenie -= doswiadczenieDoNastepnegoPoziomu;
		punktyDoWydania += 5;
		doswiadczenieDoNastepnegoPoziomu *= 1.2;
	}
}

int Postac::getAtak(void)
{
	if (this->bron == 0)
	{
		return this->atak;
	}
	else
	{
		return this->atak + this->bron->atak;
	}
}

int Postac::getZasieg(void)
{
	if (this->bron == 0)
	{
		return this->zasieg;
	}
	else
	{
		return (this->bron)->zasieg;
	}
}

int Postac::getSzybkosc(void)
{
	if (this->bron == 0)
	{
		return this->szybkosc;
	}
	else
	{
		return this->szybkosc + this->bron->szybkosc;
	}
}

int Postac::getSzczescie(void)
{
	if (bron == 0)
	{
		if (pancerz == 0)
			return this->szczescie;
		else
			return this->szczescie + this->pancerz->szczescie;
	}
	else
	{
		if (pancerz == 0)
			return this->szczescie + this->bron->szczescie;
		else
			return this->szczescie + this->bron->szczescie + this->pancerz->szczescie;
	}
}

int Postac::getObrazenia(void)
{
	if (this->bron == 0)
	{
		return this->obrazenia;
	}
	else
	{
		return this->obrazenia + this->bron->obrazenia;
	}
}

int Postac::getObrona(void)
{
	if (pancerz == 0)
		return this->obrona;
	else
		return this->obrona + this->pancerz->obrona;
}

int Postac::getKlasaPancerza(void)
{
	if (pancerz == 0)
		return this->klasa_pancerza;
	else
		return this->klasa_pancerza +this->pancerz->klasaPancerza;
}

int Postac::getMaxZdrowie(void)
{
	if (pancerz == 0)
		return this->max_zdrowie;
	else
		return this->max_zdrowie +this->pancerz->maxZdrowie;
}

int Postac::getMaxWytrzymalosc(void)
{
	if (pancerz == 0)
		return this->max_wytrzymalosc;
	else
		return this->max_wytrzymalosc + this->pancerz->maxWytrzymalosc;
}
