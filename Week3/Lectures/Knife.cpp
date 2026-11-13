#include "Knife.h"
#include <iostream>

int Knife::calcDamage()
{
	return Weapon::calcDamage();
}

void Knife::showMe()
{
	std::cout << "Knife: Serrated? " << ((mSerrated) ? "yes" : "no") << "\t";
	Weapon::showMe();
}
