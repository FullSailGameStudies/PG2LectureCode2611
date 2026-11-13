#pragma once
class Weapon
{
private:
	int mRange;
	int mDamage;

public:
	Weapon(int range, int damage);
	//to NOT-leak objects that are polymorphically destructed
	//we need a virtual destructor
	virtual ~Weapon() = default;

	//RUNTIME-polymorphism
	//STEP 1: mark the base function as `virtual`
	//	virtual tells the compiler that derived classes MIGHT override it
	virtual void showMe();
	virtual int calcDamage() = 0;//pure virtual function
	//at least 1 pure virtual makes the class abstract

	int range() const
	{
		return mRange;
	}
	int damage() const
	{
		return mDamage;
	}
};

