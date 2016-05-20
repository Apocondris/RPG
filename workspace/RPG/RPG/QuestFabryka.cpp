#include "QuestFabryka.h"
#include <iostream>
#include <string>
#include <ctime>

unique_ptr<Quest> QuestFabryka::utworzQuest(void)
{
	
	int losowaLiczba = rand() % 2; //po % podaæ liczbê dostêpnych questow
	cout << losowaLiczba << "	" << rand() % 2 << endl;
	switch (losowaLiczba)
	{
		case 0:
		{
			cout << "Wybrano quest polowania" << endl;
			return make_unique<QuestPolowania>();
			break;
		}
		case 1:
		{
			cout << "Wybrano quest przedmiotow" << endl;
			return make_unique<QuestPrzedmiotow>();
			break;
		}
	}
}

unique_ptr<Quest> QuestFabryka::utworzQuest(short opcja)
{
	switch (opcja)
	{
		case 0:
		{
			return make_unique<QuestPolowania>();
			break;
		}
		case 1:
		{
			return make_unique<QuestPrzedmiotow>();
			break;
		}
	}
}
