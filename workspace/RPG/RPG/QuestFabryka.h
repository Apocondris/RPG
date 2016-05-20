#pragma once

#include "WszystkieKlasy.h"
#include "Quest.h"
#include "QuestPolowania.h"
#include "QuestPrzedmiotow.h"
#include <memory>

class QuestFabryka
{
public:
	static unique_ptr<Quest> utworzQuest(void);
	static unique_ptr<Quest> utworzQuest(short);
};

