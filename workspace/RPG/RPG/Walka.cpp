#include "Walka.h"
#include "Postac.h"
#include "Bron.h"
#include "Przedmiot.h"
#include "Przeciwnik.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
Walka::Walka(Postac* postac, Przeciwnik* przeciwnik,int odleglosc)//:Walka(postac,przeciwnik)
{
	this->postac = postac;
	this->przeciwnik = przeciwnik;
	this->odleglosc = odleglosc;
}

Walka::~Walka()
{
}
int Walka :: start()
{
	int flaga = 0;//odpowiedzialna za wynik walki 1-jeœli wygra potwór, 2 jeœli wygra bohater, 3 jeœli bohater ucieknie
	cout << "Naprzeciw siebie staja " + postac->imie + " i " + przeciwnik->nazwa << endl;
	cout << "Ktory z nich zwyciezy w tym boju?" << endl;
	cout << "Rozpoczyna sie runda pierwsza. Runde rozpoczyna " << postac->imie+"!"<<endl;
	zasieg = postac->getZasieg();
	while ((przeciwnik->zdrowie > 0) && (postac->zdrowie > 0) && flaga ==0)
	{
		
		int opcja2 = 0;
		int opcja = 0;
		cout << "Odleglosc miedzy wami wynosi " << odleglosc<<endl;
		cout << "Bohaterowi pozostalo " << postac->wytrzymalosc <<" puntkow wytrzymalosci" <<  " i " << postac->zdrowie << " zdrowia" << endl;
		if ((postac->klasa_postaci) == "lucznik")
		{
			cout << "Bohaterowi pozostalo " << postac->strzaly << " strzal" << endl;
			
		}
		cout << "Wybierz jedna z opcji:" << endl;

		if (sprawdz_zasieg(zasieg))
		{
			cout << "1. Atak" << endl;
			cout << "2. Ruch" << endl;
			cout << "3. Ucieczka" << endl;
			if ((postac->klasa_postaci) == "lucznik" && postac->wytrzymalosc>=2 && (odleglosc <= zasieg) && postac->strzaly>0)
			{
				cout << "4. Strzal i odskok" << endl;
			}
			while (opcja == 0)
			{
				cin >> opcja;
				if (cin.fail()) { cout << "Nie jestes zbyt rozgarniety, prawda?" << endl; cin.clear(); }
				cin.ignore(100000, '\n');
				switch (opcja)
				{
				case 1:
				{
						  cout << postac->imie+" wykonuje bohaterski atak na przeciwnika!" << endl;
						  atak_postaci();
						  opcja = 1;
						  break;
				}
				case 2:
				{
						  opcja2=0;
						  while (opcja2 == 0)
						  {
							cout << "Wybierz czy podbiec czy odbiec" << endl;
							cout << "1. Podbiegnij" << endl;
							cout << "2. Odbiegnij" << endl;
							cin >> opcja2;
							switch (opcja2)
							{
								case 1:
								{
										  cout << postac->imie + " podbiega do przeciwnika" << endl;
										  opcja2 = 1;
										  podejdz(postac->getSzybkosc());
										  break;
								}
								case 2:
								{
										  cout << postac->imie + " odbiega od przeciwnika" << endl;
										  opcja2 = 2;
										  odejdz(postac->getSzybkosc());
										  break;
								}
								default:
								{
										   opcja2 = 0;
										   break;
								}
							}
						  }
						  opcja = 2;
						  break;
				}

				case 3:
				{
						  flaga = 3;
						  opcja = 3;
						  break;
				}
				
				case 4:
				{
					if ((postac->klasa_postaci) == "lucznik" && postac->wytrzymalosc>=2 && (odleglosc <= zasieg) && postac->strzaly>0)
					 {
						  cout << postac->imie + " wykonuje strzal i odskakuje do ty³u!" << endl;
						  postac->wytrzymalosc = postac->wytrzymalosc - 2;
						  odejdz((postac->getSzybkosc())/2);
						  atak_postaci();
						  opcja = 4;
					}
					else
					{
						opcja = 0;
					}
					break;
				}
				default:
				{
						   opcja = 0;
						   break;
				}

				}
			}
			if (flaga == 3)break;
		}
		else
		{
			cout << "1. Ruch" << endl;
			cout << "2. Ucieczka" << endl;
			if (((postac->klasa_postaci) == "wojownik") && postac->wytrzymalosc>=3 && (odleglosc<=(postac->getSzybkosc()+zasieg)))
			{
				cout << "3. Szarza" << endl;
			}
			if ((postac->klasa_postaci) == "lucznik" && postac->wytrzymalosc>=2 && (odleglosc <= zasieg)&&(postac->strzaly>0))
			{
				cout << "3. Strzal i odskok" << endl;
			}


			while (opcja == 0)
			{
				cin >> opcja;
				if (cin.fail()) { cout << "Nie jestes zbyt rozgarniety, prawda?" << endl; cin.clear(); }
				cin.ignore(100000, '\n');
				switch (opcja)
				{
				case 1:
				{
						  int opcja2 = 0;
						  while (opcja2 == 0)
						  {
							  cout << "Wybierz czy podbiec czy odbiec" << endl;
							  cout << "1. Podbiegnij" << endl;
							  cout << "2. Odbiegnij" << endl;
							  cin >> opcja2;
							  switch (opcja2)
							  {
							  case 1:
							  {
										opcja2 = 1;
										podejdz(postac->getSzybkosc());
										cout << postac->imie+" podbiega do przeciwnika" << endl;
										break;
							  }
							  case 2:
							  {
										opcja2 = 2;
										odejdz(postac->getSzybkosc());
										cout << postac->imie+" odbiega od przeciwnika" << endl;
										break;
							  }
							  default:
							  {
										 opcja2 = 0;
										 break;
							  }
							  }
						  }
						  opcja = 2;
						  break;
				}
				case 2:
				{
						  flaga = 3;
						  opcja = 3;
						  break;
				}
				case 3:
				{
						  if (((postac->klasa_postaci) == "wojownik") && (postac->wytrzymalosc)>=3 && (odleglosc <= (postac->getSzybkosc() + zasieg)))
						  {
							  cout << postac->imie + " wykonuje bohaterska szarze na przeciwnika" << endl;
							  postac->wytrzymalosc = postac->wytrzymalosc - 3;
							  podejdz(postac->getSzybkosc());
							  atak_postaci();
							  opcja = 4;
						  }
						  else if ((postac->klasa_postaci) == "lucznik" && postac->wytrzymalosc>=2 && (odleglosc <= zasieg) && postac->strzaly>0)
						  {
							  cout << postac->imie + " wykonuje strzal i odskakuje do ty³u!" << endl;
							  postac->wytrzymalosc = postac->wytrzymalosc - 2;
							  odejdz((postac->getSzybkosc()) / 2);
							  atak_postaci();
							  opcja = 4;
						  }
						  else
						  {
							  opcja = 0; 
						  }
						  break;
				}
				default:
				{
						   opcja = 0;
						   break;
				}
				if (flaga == 3)break;
				}
			}
		}
		if (przeciwnik->zdrowie <= 0)
		{
			flaga = 2;
			break;
		}

	/////////przeciwnik
		if (sprawdz_zasieg(przeciwnik->zasieg))
		{
			cout << przeciwnik->nazwa + " atakuje w szale bohatera!" << endl;
			atak_przeciwnika();
		}
		else
		{
			cout << przeciwnik->nazwa + " podbiega!" << endl;
			podejdz(przeciwnik->szybkosc);
		}
		if (postac->zdrowie <= 0)
		{
			flaga = 1;
			break;
		}
		system("pause");
		czyscEkran();
	}
	/*
	switch (flaga)
	{
		case 1:
		{
				  cout << "Walka zakonczyla sie zwyciêstwem przeciwnika!" << endl;
				  break;
		}
		case 2:
		{
				  cout << "Walka zakonczyla sie zwyciêstwem bohatera!" << endl;
				  break;
		}
		case 3:
		{
				  cout << "Walka zakonczyla sie rozpaczliwa ucieczka bohatera" << endl;
				  break;
		}
	}*/
	return flaga;
};

void Walka :: atak_postaci()
{

	srand(time(NULL));
	int trafienie=((postac->getAtak())-(przeciwnik->obrona))+(rand()%10);
	if (trafienie > 0)
	{
		int obrazenia;
		if (szczescie(postac->getSzczescie()))
		{
			obrazenia = (postac->getObrazenia()) * 2;
			obrazenia = obrazenia - losuj_pancerz(przeciwnik->klasa_pancerza);
			cout << "Dzieki odrobinie szczesci bohater zadaje podwojne obrazenia!" << endl;
		}
		else
		{
			obrazenia = (postac->getObrazenia()) - losuj_pancerz(przeciwnik->klasa_pancerza);
		}

		if (szczescie(przeciwnik->szczescie))
		{
			obrazenia = 0;
			cout << "Przeciwnik cudem uniknal ciosu!" << endl;
		}
		cout << "Bohater zadal " << obrazenia << " punktow obrazen" << endl;
		przeciwnik->zdrowie = przeciwnik->zdrowie - obrazenia;
		cout << "Przeciwnikowi pozostalo " << przeciwnik->zdrowie << " punktow zycia" << endl;
		if ((postac->klasa_postaci) == "lucznik" && postac->strzaly > 0)
		{
			postac->strzaly = postac->strzaly - 1;
			if (postac->strzaly <= 0)zasieg = postac->zasieg;
		}
	}
	else
	{
		cout << "Nie udalo sie trafic!" << endl;
		if ((postac->klasa_postaci) == "lucznik" && postac->strzaly > 0)
		{
			postac->strzaly = postac->strzaly - 1;
			if (postac->strzaly <= 0)zasieg = postac->zasieg;
		}

	}
	

};

void Walka::atak_przeciwnika()
{

	srand(time(NULL));
	int trafienie = ((przeciwnik->atak) - (postac->getObrona())) + (rand() % 10);
	if (trafienie > 0)
	{
		int obrazenia;
		if (szczescie(przeciwnik->szczescie))
		{
			obrazenia = (przeciwnik->obrazenia) * 2;
			obrazenia = obrazenia - losuj_pancerz(postac->getKlasaPancerza());
			cout << "Do przeciwnika usmiechnelo sie szczescie! Zadaje podwojne obrazenia" << endl;
		}
		else
		{
			obrazenia = (przeciwnik->obrazenia) - losuj_pancerz(postac->getKlasaPancerza());
		}

		if (szczescie(postac->getSzczescie()))
		{
			obrazenia = 0;
			cout << "Bohater cudem uniknal ciosu!" << endl;
		}
		cout << "Przeciwnik zadal " << obrazenia << " punktow obrazen" << endl;
		postac->zdrowie = postac->zdrowie - obrazenia;
		cout << "Bohaterowi pozostalo " << postac->zdrowie << " punktow zycia" << endl;
	}
	else
	{
		cout << "Nie udalo sie trafic!" << endl;
	}
};

void Walka::podejdz(int szybkosc)
{
	if(odleglosc>szybkosc)odleglosc=odleglosc - szybkosc;
	else odleglosc = 1;
	if (odleglosc <= 0)odleglosc = 1;
};
void Walka::odejdz(int szybkosc)
{
	odleglosc = odleglosc + szybkosc;
};

bool Walka::szczescie(int szczescie)
{
	srand(time(NULL));
	int wynik = rand() % 100;
	wynik = wynik + szczescie;
	if (wynik > 90) return true;
	else return false;
};

int Walka::losuj_pancerz(int pancerz)
{
	srand(time(NULL));
	if (pancerz == 0)return 0;
	else return rand() % pancerz;
};
bool Walka::sprawdz_zasieg(int zasieg)
{
	if ((odleglosc - zasieg) <= 0)return true;
	else return false;
};

void Walka::czyscEkran(void)
{
	system("CLS");
}

