#include <iostream>
#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib>
#include <stdlib.h>

#include "WszystkieKlasy.h"
using namespace std;


class Walka
{

public:

	Walka(Postac*, Przeciwnik*,int odleglosc);
	~Walka();
	Postac* postac;
	Przeciwnik* przeciwnik;
	int start();

private:
	int odleglosc;
	void atak_postaci();
	void atak_przeciwnika();
	void podejdz(int szybkosc);
	void odejdz(int szybkosc);
	bool szczescie(int szczescie);
	int losuj_pancerz(int pancerz);
	bool sprawdz_zasieg(int zasieg);
	void czyscEkran(void);
	int zasieg;
};