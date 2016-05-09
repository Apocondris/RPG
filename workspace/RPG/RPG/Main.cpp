#include <iostream>
#include "Gra.h"
#include <time.h>

using namespace std;

int main() 
{
	srand(time(NULL));
	Gra gra;
	gra.ustawKonsole(100,30);
	gra.start();
	cout << endl << endl << "Koniec programu" << endl;
	system("pause");
	return 0;
}