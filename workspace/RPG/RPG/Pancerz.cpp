#include "Pancerz.h"



Pancerz::Pancerz(string nazwa, int szczescie = 0, int obrona = 0, int klasaPancerza = 0, int maxZdrowie = 0, int maxWytrzymalosc = 0)
{
	this->nazwa = nazwa;
	this->szczescie = szczescie;
	this->obrona = obrona;
	this->klasaPancerza = klasaPancerza;
	this->maxZdrowie = maxZdrowie;
	this->maxWytrzymalosc = maxWytrzymalosc;
}

string Pancerz::toString(void)
{
	string str = "Pancerz: ";
	str += nazwa + "	";
	str += "obrona: " + to_string(obrona) + "	";
	str += "klasa pancerza: " + to_string(klasaPancerza) + "	";
	str += "szczescie: " + to_string(szczescie) + "	";
	str += "premia do zdrowia: " + to_string(maxZdrowie) + "	";
	str += "premia do wytrzymalosc: " + to_string(maxWytrzymalosc);
	return str;
}
