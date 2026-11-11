#pragma once
#include "Weapon.h"

//IS-A relationship
//Pistol IS-A Weapon
class Pistol : public Weapon
{
public:

	Pistol(int range, int damage, int ammo, int capacity) :
		//call the base ctor in the member initialization list
		Weapon(range,damage),
		mAmmo(ammo), 
		mCapacity(capacity)
	{
	
	}


	int Ammo() const { return mAmmo; }
	int Capacity() const { return mCapacity; }

	void Ammo(int ammo)
	{
		if (ammo >= 0 and ammo <= mCapacity)
			mAmmo = ammo;
	}
	void Capacity(int cap)
	{
		if (cap > 0 and cap <= 100)
			mCapacity = cap;
	}

private:
	//Good OOD Practice:
	//  favor HAS-A over IS-A (improved flexibility)
	// 
	//HAS-A relationship (the COMPOSITION)
	//what is this class COMPOSED of
	//Pistol HAS-A mAmmo
	int mAmmo;
	int mCapacity;
};

