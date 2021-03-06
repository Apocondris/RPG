#include "OknoPostaci.h"
#include "Postac.h"
#include <string> 
#include <SFML/Graphics.hpp>
using namespace std;

OknoPostaci::OknoPostaci(shared_ptr<Postac> postac)
{
	this->postac = postac;
}

void OknoPostaci::start()
{
	utworzOkno();

	bool wczytanoZasoby = true;
	sf::Font font;
	if (!font.loadFromFile("font.ttf"))
	{
		cout << "Nie wczytano czcionki";
		wczytanoZasoby = false;
	}
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
		okno.clear(sf::Color::White); // czyszczenie okna na bialy kolor (nie trzeba podawa� argumentu, standardowo czy�ci si� na czarny)

		okno.draw(sprite);
		rysujStatystyki(text);
		
        sf::Event event; // sprawdzenie czy nie powsta�y jakie� eventy, kt�re trzeba obs�u�y�
        while (okno.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)  // klikni�cie przycisku [X]
				okno.close();
        }

		okno.display();
	}
	okno.clear(sf::Color::Red);
}

void OknoPostaci::utworzOkno(void)
{
	okno.create(sf::VideoMode(350, 600), "Postac");
	// zmiana pozycji okna (wzgl�dem pulpitu)
	okno.setPosition(sf::Vector2i(1200, 150));
	okno.setVerticalSyncEnabled(true);
	okno.setFramerateLimit(10);
}

void OknoPostaci::rysujStatystyki(sf::Text text)
{
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
		text.setString("Zdrowie: " + to_string(postac->zdrowie) + " / " + to_string(postac->getMaxZdrowie()));
		okno.draw(text);
		text.setPosition(x, y += 35);
		text.setString("Wytrzymalosc: " + to_string(postac->wytrzymalosc) + " / " + to_string(postac->getMaxWytrzymalosc()));
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
	
}
