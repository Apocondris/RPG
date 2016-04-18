#pragma once

#ifndef POSTAC_H
#define POSTAC_H

#include <iostream>
#include <string>

using namespace std;

class Postac
{
public:
	string imie;

	Postac();
	Postac(string);
	~Postac();

protected:
	int zdrowie;
	int punktyDoWydania;
	//TODO statystyki
};

#endif