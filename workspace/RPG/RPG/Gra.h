#pragma once

#include <iostream>
#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib>
#include <stdlib.h>

#include "Postac.h"
#include "Wojownik.h"
#include "Lucznik.h"
#include "Lokalizacja.h"
using namespace std;

class Gra
{

public:
	Postac* postac;

	static void ustawKonsole(int Width = 100, int Height = 50);
	static void czyscEkran(void);
	static string logo(void);

	void start();
	void ekranMenu(void);
	void tworzeniePostaci(void);
	Lokalizacja* losujLokalizacje(void);

private:
	void wybierzAkcje(void);
};

