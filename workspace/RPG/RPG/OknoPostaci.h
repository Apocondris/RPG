#pragma once

#include "WszystkieKlasy.h"
#include <SFML/Graphics.hpp>
using namespace std;

class OknoPostaci
{
public:
	OknoPostaci(Postac *);
	~OknoPostaci();

	void start();
	
	sf::RenderWindow okno;

private:
	Postac * postac;
};

