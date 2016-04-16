#include "Gra.h"

using namespace std;

void Gra::start()
{
	ekranMenu();
	wybierzAkcje();
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
}

void Gra::wybierzAkcje()
{
	int wybranaAkcja;
	cin >> wybranaAkcja;
	switch (wybranaAkcja)
	{
		case 1 : 
		{
			tworzeniePostaci();
			break;
		}
		case 2 :
		{
			system("exit");
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
	cin >> imie;

	cout << "Wybierz klase postaci: " << endl
		<< "1) wojownik" << endl
		<< "2) lucznik"<< endl << endl
		<< "Jaka klase wybierasz? ";
	cin >> klasa;
	
	postac = new Postac(imie);

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