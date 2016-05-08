#include "QuestFabryka.h"
#include "QuestPolowania.h"
#include "QuestPrzedmiotow.h"
#include <iostream>
#include <string>
#include <ctime>

Quest * QuestFabryka::utworzQuest(void)
{
	srand(time(NULL));
	int losowaLiczba = rand() % 2; //po % podaæ liczbê dostêpnych przeciwnikow
	cout << losowaLiczba << "	" << rand() % 2 << endl;
	switch (losowaLiczba)
	{
		case 0:
		{
			cout << "Wybrano quest polowania" << endl;
			return new QuestPolowania();
			break;
		}
		case 1:
		{
			cout << "Wybrano quest przedmiotow" << endl;
			return new QuestPrzedmiotow();
			break;
		}
	}
}

Quest * QuestFabryka::utworzQuest(short opcja)
{
	switch (opcja)
	{
		case 0:
		{
			return new QuestPolowania();
			break;
		}
		case 1:
		{
			return new QuestPrzedmiotow();
			break;
		}
	}
}
