#pragma once

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
	void ekranMenu(void);
	void tworzeniePostaci(void);
	shared_ptr<Lokalizacja> losujLokalizacje(void);
	static void czyscEkran(void);
	void logo(void);

private:

};

