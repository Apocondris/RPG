#include "QuestPolowania.h"



QuestPolowania::QuestPolowania(string nazwaCelu, int iloscCelow) : Quest(nazwaCelu, iloscCelow)
{
	nazwaQuesta = "Upoluj " + nazwaCelu;
	opis = "Poszukuje smialka ktory wytropi i zabije " + to_string(iloscCelow) + "x " + nazwaCelu;
}
