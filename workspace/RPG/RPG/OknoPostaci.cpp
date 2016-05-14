#include "OknoPostaci.h"
#include "Postac.h"
#include <string> 
#include <SFML/Graphics.hpp>
using namespace std;

OknoPostaci::OknoPostaci(Postac * postac)
{
	this->postac = postac;
	okno.create(sf::VideoMode(350, 600), "Postac");
	// zmiana pozycji okna (wzglêdem pulpitu)
	okno.setPosition(sf::Vector2i(1200, 150));
	okno.setActive(false);
}

OknoPostaci::~OknoPostaci()
{
	if (postac != 0)
	{
		delete postac;
		postac = 0;
	}
}

void OknoPostaci::start()
{
	bool wczytanoZasoby = true;
	//okno.setActive(true);
	sf::Font font;
	if (!font.loadFromFile("font.ttf"))
	{
		cout << "Nie wczytano czcionki";
		wczytanoZasoby = false;
	}

	sf::CircleShape shape(50);
	shape.setFillColor(sf::Color::Green);

	sf::Text text;
	text.setFont(font);
	text.setColor(sf::Color::Black);

	sf::Texture texture;
	texture.setSmooth(true);
	sf::Sprite sprite;
	if (postac->klasa_postaci == "lucznik")
	{
		if (!texture.loadFromFile("lucznik.jpg"))
		{
			cout << "Nie wczytano obrazow";
			wczytanoZasoby = false;
		}
		sprite.setTexture(texture);
		sprite.setPosition(60., 10.);
		sprite.setScale(0.48, 0.48);
	}
	else if(postac->klasa_postaci == "wojownik")
	{
		if (!texture.loadFromFile("wojownik.jpg"))
		{
			cout << "Nie wczytano obrazow";
			wczytanoZasoby = false;
		}
		sprite.setTexture(texture);
		sprite.setPosition(40., 10.);
		sprite.setScale(0.43, 0.43);
	}

	while (okno.isOpen() && wczytanoZasoby)
	{
		sf::sleep(sf::milliseconds(150));
		// czyszczenie okna na bialy kolor (nie trzeba podawaæ argumentu, standardowo czyœci siê na czarny)
		okno.clear(sf::Color::White);

		okno.draw(sprite);

		float y = 330.;
		float x = 10.;

		text.setCharacterSize(25U);
		text.setPosition(x, y);
		text.setString("Imie: " + postac->imie);
		okno.draw(text);
		text.setPosition(x, y+=35);
		text.setString("Klasa: " + postac->klasa_postaci);
		okno.draw(text);
		text.setPosition(x, y += 35);
		text.setString("Zdrowie: " + to_string(postac->zdrowie) + " / " + to_string(postac->max_zdrowie));
		okno.draw(text);
		text.setPosition(x, y += 35);
		text.setString("Wytrzymalosc: " + to_string(postac->wytrzymalosc) + " / " + to_string(postac->max_wytrzymalosc));
		okno.draw(text);

		text.setCharacterSize(20U);
		text.setPosition(x, y += 55);
		text.setString("Atak: " + to_string(postac->getAtak()));
		okno.draw(text);
		text.setPosition(x + 180, y);
		text.setString("Obrona: " + to_string(postac->getObrona()));
		okno.draw(text);
		text.setPosition(x, y += 25);
		text.setString("Szybkosc: " + to_string(postac->getSzybkosc()));
		okno.draw(text);
		text.setPosition(x + 180, y);
		text.setString("Szczescie: " + to_string(postac->getSzczescie()));
		okno.draw(text);
		text.setPosition(x, y += 25);
		text.setString("Zasieg: " + to_string(postac->getZasieg()));
		okno.draw(text);
		text.setPosition(x + 180, y);
		text.setString("Obrazenia: " + to_string(postac->getObrazenia()));
		okno.draw(text);
		if (postac->klasa_postaci == "lucznik")
		{
			text.setPosition(x, y += 25);
			text.setString("Posiadane strzaly: " + to_string(postac->strzaly));
			okno.draw(text);
		}

		okno.display();
	}
	okno.clear(sf::Color::Red);
}
