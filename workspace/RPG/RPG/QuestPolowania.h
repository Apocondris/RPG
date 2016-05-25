#pragma once

#include "Quest.h"
#include "WszystkieKlasy.h"
#include <memory>

class QuestPolowania : public Quest
{
public:
	QuestPolowania();

private:
	shared_ptr<Przeciwnik> losujCelPolowania(void);
};
