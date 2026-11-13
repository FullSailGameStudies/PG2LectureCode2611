#pragma once
#include "Weapon.h"
class Knife : public Weapon
{
public:
	Knife(int range, int damage, bool mSerrated) : 
		Weapon(range,damage), 
		mSerrated(mSerrated)
	{}
	int calcDamage() override;
	void showMe() override;

	bool Serrated() const { return mSerrated; }
	void Serrated(bool serrated)
	{
		mSerrated = serrated;
	}

private:
	bool mSerrated;
};

