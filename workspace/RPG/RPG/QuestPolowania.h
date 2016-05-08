#pragma once

#include "Quest.h"
#include "WszystkieKlasy.h"

class QuestPolowania : public Quest
{
public:
	QuestPolowania();

private:
	Przeciwnik * losujCelPolowania(void);
};
