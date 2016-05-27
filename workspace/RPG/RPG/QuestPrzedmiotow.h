#pragma once

#include "Quest.h"
#include "WszystkieKlasy.h"

class QuestPrzedmiotow : public Quest
{
public:
	QuestPrzedmiotow();

private:
	Przedmiot* losujCel(void);
};

