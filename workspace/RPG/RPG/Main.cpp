#include <iostream>
#include "Gra.h"
#include <ctime>

using namespace std;

int main() 
{
	srand(time(0));
	Gra gra;
	gra.ustawKonsole(100,30);
	gra.start();
	cout << endl << endl << "Koniec programu" << endl;
	system("pause");
	return 0;
}