#include "Pistol.h"
#include <iostream>


//RUNTIME-polymorphism
//STEP 3: add the definition to the derived class
void Pistol::showMe()
{
	//2 kinds of overrides:
	//1) FULL override: don't call the base function
	//2) EXTENSION override: call the base function

	std::cout << "Pistol: " << mAmmo << " / " << mCapacity << "\t";
	//call the base
	Weapon::showMe();
}