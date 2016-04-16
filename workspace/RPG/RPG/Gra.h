#pragma once

#include <iostream>
#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib>
#include <stdlib.h>

#include "Postac.h"
using namespace std;

class Gra
{

public:
	Postac postac;
	string aaa;

	void start();
	void ustawKonsole(int Width = 100, int Height = 50);
	void czyscEkran();
	string logo(void);
	void ekranMenu(void);
	void wybierzAkcje();
	void tworzeniePostaci(void);
};

