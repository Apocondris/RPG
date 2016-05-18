#include <iostream>
#include "Gra.h"
#include <ctime>
#include <SFML\Audio.hpp>

using namespace std;

int main() 
{

	sf::Music music;
	music.setLoop(true);
	if (!music.openFromFile("podklad.ogg"))
	{
		system("pause");
		return -1; 
	}
	//music.play();

	srand(time(NULL));
	Gra gra;
	gra.ustawKonsole(100,40);
	gra.start();
	cout << endl << endl << "Koniec programu" << endl;
	system("pause");
	return 0;
}