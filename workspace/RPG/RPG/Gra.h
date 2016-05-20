#pragma once

#include <iostream>
#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib>
#include <stdlib.h>
#include <memory>

#include "WszystkieKlasy.h"
using namespace std;

class Gra
{

public:
	shared_ptr<Postac> postac;

	static void ustawKonsole(int Width = 100, int Height = 50);

	void start();

private:
	static void czyscEkran(void);
	void logo(void);
	void ekranMenu(void);
	void tworzeniePostaci(void);
	shared_ptr<Lokalizacja> losujLokalizacje(void);

private:

};

