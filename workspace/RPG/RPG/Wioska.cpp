#include "Wioska.h"



Wioska::Wioska()
{
}

Wioska::Wioska(Postac * postac) : Lokalizacja(postac)
{
}

Wioska::Wioska(Postac * postac, Lokalizacja * lokalizacja) : Lokalizacja(postac, lokalizacja)
{

}


Wioska::~Wioska()
{
}

void Wioska::start(void)
{
	bool przebywaszWWiosce = true;

	czyscEkran();
	cout << "Przybyles do wioski.."<< endl;
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
	cout << "Znajdujesz sie w wiosce" << endl
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
