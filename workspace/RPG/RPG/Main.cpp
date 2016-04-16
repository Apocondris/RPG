#include <iostream>
#include "Gra.h"

using namespace std;

int main() 
{

	Gra gra;
	gra.ustawKonsole();
	gra.start();
	cout << endl << endl << "Koniec programu" << endl;
	system("pause");
	return 0;
}