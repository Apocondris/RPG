#include <iostream>
#include "Gra.h"
#include <ctime>

using namespace std;

int main() 
{
	srand(time(nullptr));
	Gra gra;
	gra.ustawKonsole(100,30);
	gra.start();
	cout << endl << endl << "Koniec programu" << endl;
	system("pause");
	return 0;
}