#pragma once

#include "WszystkieKlasy.h"
#include <SFML/Graphics.hpp>
#include <memory>
using namespace std;

class OknoPostaci
{
public:
	OknoPostaci(shared_ptr<Postac>);

	void start();
	
	sf::RenderWindow okno;


private:
	shared_ptr<Postac> postac;

	void utworzOkno(void);
	void rysujStatystyki(sf::Text text);
};

