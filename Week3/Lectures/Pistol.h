#pragma once
#include "Weapon.h"

//IS-A relationship
//Pistol IS-A Weapon
class Pistol : public Weapon
{
public:

	Pistol(int range, int damage, int ammo, int capacity) :
		//call the base ctor in the member initialization list
		Weapon(range, damage),
		mAmmo(ammo),
		mCapacity(capacity)
	{

	}

	Pistol operator+(Pistol& other)
	{
		int ammo = mAmmo + other.mAmmo;
		Pistol newGun(range(), damage(), ammo, mCapacity);
		return newGun;
	}
	Pistol operator+(int moreRounds)
	{
		int ammo = mAmmo + moreRounds;
		Pistol newGun(range(), damage(), ammo, mCapacity);
		return newGun;
	}

	//Function overloading
	//the functions MUST be different on the parameters
	//- either the number of parameters
	//- OR the types of the parameters
	int Ammo() const { return mAmmo; }
	void Ammo(int ammo)
	{
		if (ammo >= 0 and ammo <= mCapacity)
			mAmmo = ammo;
	}

	int Capacity() const { return mCapacity; }
	void Capacity(int cap)
	{
		if (cap > 0 and cap <= 100)
			mCapacity = cap;
	}


	//RUNTIME-polymorphism
	//STEP 2: add a declaration that matches EXACTLY the base declaration
	//  you do NOT need to add `virtual` to the derived function
	//
	//OPTIONALLY: you can add the `override` keyword
	void showMe() override;

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

