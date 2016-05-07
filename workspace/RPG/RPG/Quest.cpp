#include "Quest.h"



Quest::Quest(string nazwaKlucza, int ilosc, unsigned short wartoscCelu)
{
	this->nazwaKlucza = nazwaKlucza;
	this->ilosc = ilosc;
	this->nagroda = ilosc * wartoscCelu;
	aktualnaIlosc = 0;
}
