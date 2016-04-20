#include "Gra.h"

using namespace std;

void Gra::start()
{
	ekranMenu();
}

void Gra::ustawKonsole(int Width, int Height)
{
	_COORD coord;
	coord.X = Width;
	coord.Y = Height;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle 
	SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size 
	SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size 
}

void Gra::czyscEkran()
{
	system("CLS");
}

void Gra::ekranMenu(void)
{
	//ustawKonsole();
	cout << logo() << endl;
	cout << "Znajdujesz sie na ekranie glownym. Masz do wyboru jedna z ponizszych opcji:" << endl
		<< "1) Nowa gra" << endl
		<< "2) Wyjscie" << endl << endl
		<< "Teraz wpisz liszbe z klawiatury i wybierz co chcesz zrobic: ";
	wybierzAkcje();
}

void Gra::wybierzAkcje()
{
	int wybranaAkcja;
	cin >> wybranaAkcja;
	if (cin.fail()) { cout << "Nie jestes zbyt rozgarniety, prawda?" << endl; cin.clear(); }
	cin.ignore(100000, '\n');
	switch (wybranaAkcja)
	{
		case 1 : 
		{
			tworzeniePostaci();
			Lokalizacja* lokalizacja = losujLokalizacje();
			lokalizacja->start();
			break;
		}
		case 2 :
		{
			exit(0);
			break;
		}
		default :
		{
			cout << "Niepoprawny wybor." << endl 
				<< "Wybierz jeszcze raz: ";
			wybierzAkcje();
			break;
		}
	}
}

void Gra::tworzeniePostaci(void)
{
	string imie;
	int klasa;

	czyscEkran();
	cout << logo() << endl;

	cout << "Okno tworzenia twojej postaci." << endl << endl << endl
		<< "Podaj imie postaci: ";
	//cin >> imie;
	getline(cin, imie);
	//cin.ignore(100000, '\n');

	cout << "Wybierz klase postaci: " << endl
		<< "1) wojownik" << endl
		<< "2) lucznik"<< endl << endl
		<< "Jaka klase wybierasz? ";
	cin >> klasa;
	if (cin.fail()) { cout << "Nie jestes zbyt rozgarniety, prawda?" << endl; cin.clear();}
	cin.ignore(100000, '\n');
	
	switch (klasa)
	{
		case 1 :
		{
			postac = new Wojownik(imie);
			cout << endl << "Witaj " << postac->imie << endl
				<< "Swoja przygode bedziesz toczyl jako wojownik" << endl;
			break;
		}
		case 2:
		{
			postac = new Lucznik(imie);
			cout << endl << "Witaj " << postac->imie << endl
				<< "Swoja przygode bedziesz toczyl jako lucznik" << endl;
			break;
		}
		default :
		{
			cout << "Wprowadzaone przez Ciebie dane nie sa poprawne." << endl;
			system("pause");
			tworzeniePostaci();
			break;
		}
	}
	system("pause");
}

Lokalizacja* Gra::losujLokalizacje(void)
{
	int losowaLiczba = rand()%1; //po % podaæ liczbê dostêpnych lokalizacji
	switch (losowaLiczba)
	{
		case 0 :
		{
			return new Wioska(postac);
			break;
		}
		default :
		{
			return new Lokalizacja(postac);
			break;
		}
	}
}


string Gra::logo(void)
{
	//100 x 10
	string wynik = "";
	wynik += "####################################################################################################";
	wynik += "###############        ###################        #####################      #######################";
	wynik += "###############  #####  ##################  #####  ##################  ######  #####################";
	wynik += "###############  #####  ##################  #####  ##################  #############################";
	wynik += "###############  #####  ##################  #####  ##################  #############################";
	wynik += "###############        ###################        ###################  #####     ###################";
	wynik += "###############  ##   ####################  #########################  ######  #####################";
	wynik += "###############  ###   ###################  #########################  ######  #####################";
	wynik += "###############  ####   ##################  ###########################      #######################";
	wynik += "####################################################################################################\n";
	return wynik;
}