#include "FabrykaWyposazenia.h"
#include "Bron.h"
#include "Przedmiot.h"
#include "Pancerz.h"
#include <ctime>

Bron * FabrykaWyposazenia::stworzMiecz(int zasieg, int obrazenia, int szybkosc, int szczescie, int atak)
{
	Bron * bron = new Bron("miecz", szybkosc, szczescie, atak, zasieg, obrazenia);
	return bron;
}

Bron * FabrykaWyposazenia::stworzLuk(int zasieg, int obrazenia, int szybkosc, int szczescie, int atak)
{
	Bron * bron = new Bron("luk", szybkosc, szczescie, atak, zasieg, obrazenia);
	return bron;
}

Pancerz * FabrykaWyposazenia::stworzPancerz(int szczescie, int obrona, int klasaPancerza, int maxZdrowie, int maxWytrzymalosc)
{
	Pancerz * pancerz = new Pancerz("pancerz", szczescie, obrona, klasaPancerza, maxZdrowie, maxWytrzymalosc);
	return pancerz;
}

Bron * FabrykaWyposazenia::generujMiecz()
{
	srand(time(NULL));
	Bron * bron = new Bron("miecz", rand() % 10, rand() % 10, rand() % 10, (rand() % 2)+1, rand() % 30);
	return bron;
}

Bron * FabrykaWyposazenia::generujLuk()
{
	srand(time(NULL));
	Bron * bron = new Bron("luk", rand() % 10, rand() % 10, rand() % 10, (rand() % 8) + 7, rand() % 30);
	return bron;
}

Pancerz * FabrykaWyposazenia::generujPancerz()
{
	srand(time(NULL));
	Pancerz * pancerz = new Pancerz("pancerz", rand() % 10, rand() % 30, rand() % 30, rand() % 50, rand() % 50);
	return pancerz;
}

Przedmiot * FabrykaWyposazenia::generujWyposazenie()
{
	srand(time(NULL));
	short losowaLiczba = rand() % 3; //ilosc dostepnych rodzajow wyposazenia
	switch (losowaLiczba)
	{
		case 0:
		{
			return generujMiecz();
			break;
		}
		case 1:
		{
			return generujLuk();
			break;
		}
		case 2:
		{
			return generujPancerz();
			break;
		}
	}
}
