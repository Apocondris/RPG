#include "Wioska.h"



string Wioska::nazwyWiosek[iloscNazw];

Wioska::Wioska()
{
	if (czyNazwyLokalizacjiSaPuste())
	{
		ladujNazwyLokalizacji("NazwyWiosek.txt");
	}
	this->nazwa = pobierzNazwe();
}

Wioska::Wioska(Postac * postac) : Lokalizacja(postac)
{
	if (czyNazwyLokalizacjiSaPuste())
	{
		ladujNazwyLokalizacji("NazwyWiosek.txt");
	}
	this->nazwa = pobierzNazwe();
}

Wioska::Wioska(Postac * postac, Lokalizacja * lokalizacja) : Lokalizacja(postac, lokalizacja)
{
	if (czyNazwyLokalizacjiSaPuste())
	{
		ladujNazwyLokalizacji("NazwyWiosek.txt");
	}
	this->nazwa = pobierzNazwe();
}


Wioska::~Wioska()
{
}

void Wioska::start(void)
{
	bool przebywaszWWiosce = true;

	//czyscEkran();
	//cout << "Przybyles do wioski "<< this->nazwa << ".." << endl;
	//system("pause");

	while (przebywaszWWiosce)
	{
		czyscEkran();
		cout << logo();
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
	if (cin.fail()) { cout << "Nie jestes zbyt rozgarniety, prawda?" << endl; cin.clear(); }
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

string Wioska::logo()
{
	//100 x 12
	string wynik = "";
	wynik += "     ############   ###############################      ############### #############        ######";
	wynik += " #  ##########   ##  #       #################                 ######     #########                 ";
	wynik += "   ############            ##################         ####  ## ###################   #####         #";
	wynik += "################## ###################################### ##########################################";
	wynik += "####################################################################################################";
	wynik += "####################################################################################################";
	wynik += "####################################################################################################";
	wynik += "####################################################################################################";
	wynik += "##################^^^^^###############################^^^^^^^###############^^^^^^^#################";
	wynik += "#################^_____^#############################^KARCZMA^#############^_______^################";
	wynik += "#################%% %% %#############################% %%^^% %#############%  %  % %################";
	wynik += "#################%%%%%%%#############################%%%%  %%%#############%  %  % %################\n";
	return wynik;
}
