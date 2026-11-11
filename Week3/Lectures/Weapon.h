#pragma once
class Weapon
{
private:
	int mRange;
	int mDamage;

public:
	Weapon(int range, int damage);

	//RUNTIME-polymorphism
	//STEP 1: mark the base function as `virtual`
	//	virtual tells the compiler that derived classes MIGHT override it
	virtual void showMe();
	int calcDamage();

	int range() const
	{
		return mRange;
	}
	int damage() const
	{
		return mDamage;
	}
};

