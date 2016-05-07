#include "QuestPolowania.h"
#include "BandytaLucznik.h"
#include "BandytaWojownik.h"
#include "Dzik.h"
#include "Wilk.h"
#include "Niedzwiedz.h"
#include "Utopiec.h"



QuestPolowania::QuestPolowania(Przeciwnik * nazwaCelu, int iloscCelow) : Quest(nazwaCelu->nazwa, iloscCelow, nazwaCelu->wartosc)
{
	nazwaQuesta = "Upoluj " + nazwaCelu->nazwa;
	opis = "Poszukuje smialka ktory wytropi i zabije " + to_string(iloscCelow) + "x " + nazwaCelu->nazwa;
}
