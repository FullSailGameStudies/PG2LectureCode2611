#include <iostream>
#include "Console.h"
#include "Day7.h"
#include "Day8.h"
#include "Day9.h"
#include "Input.h"
#include "Player.h"
#include "Color.h"
#include <Pistol.h>
#include "Knife.h"

void Counter()
{
	//the creation & initialization happens the first time only
	static int i = 0;
	std::cout << i << " ";
	i++;
}
void Other()
{
	static int i = 0;
	std::cout << i << " ";
}
void SomeFunc()
{
	int secret = rand();
}
int main(int argc, char* args[])
{
	//all of these variables are on the stack section of memory
	int num = 5;
	int& rNum = num;
	int* pNum = &num;
	std::cout << rNum << "\n";
	std::cout << pNum << "\n";
	//dereference the pointer to access the value it points to
	std::cout << *pNum << "\n";

	Pistol* pGun;
	{
		// ` = new` always creates something in the Heap
		int* hNum = new int(5);
		std::cout << hNum << "\n";

		Pistol* heapGun = new Pistol(200, 50, 2, 5);
		pGun = heapGun;

		//every `=new` REQUIRES a `delete`
		//delete the heap objects when you are done with them
		delete hNum;
		delete heapGun;
		heapGun = nullptr;
	}
	//pGun->calcDamage();



	for (int i = 0; i < 10; i++)
	{
		Counter();
	}
	Other();
	Pistol pewpew(100, 250, 15, 50);
	Pistol p2(100, 250, 5, 50);
	int ammo = pewpew.Ammo();
	pewpew = pewpew + p2;//pewpew+(p2)
	pewpew = pewpew + 5;//pewpew+(5)
	pewpew = p2;//calls the assignment operator


	Pistol* currentGun = &pewpew;
	//when using pointers to classes, better to use `->` to dereference
	currentGun->showMe();
	(*currentGun).showMe();

	//UPCAST:
	//casting from a derived type (Pistol)
	//to a base type (Weapon)
	//ALWAYS safe!!
	Weapon* currentWeapon = currentGun;
	currentGun->showMe();
	currentWeapon->showMe();

	Knife stabby(3, 10, true);
	currentWeapon = &stabby;
	currentWeapon->showMe();

	std::vector<Weapon*> inventory;
	inventory.push_back(&pewpew);//upcasting
	inventory.push_back(&stabby);//upcasting

	std::cout << "\n\nJohn Wick's Inventory:\n";
	for (auto& wpn : inventory)
	{
		wpn->showMe();//runtime polymorphism
	}
	std::cout << "\n\n";

	//DOWNCAST:
	//casting from a base type (Weapon)
	//to a derived type (Knife)
	//NOT SAFE!!!!

	pewpew.showMe();

	Color clr(255, 0, 0, 255);
	clr.green = 127;

	//initialize it when creating it
	//EVERY class instance requires a constructor call
	//p1 is an instance of the Player class
	Player p1("BruceW", 100);//calls the ctor
	std::cout << "Player 1: " <<
		p1.GetName() << " Level: " <<
		p1.Level() << "\n";

	std::string hello = "Hello Week 3!";
	for (auto& ch : hello)
	{
		Console::Write(ch, (ConsoleColor)(rand() % 7 + 1));
	}
	std::cout << "\n";

	int menuSelection = 0;
	std::vector<std::string> menuOptions{
		"1. Part A-1: Create Class",//classes + inheritance + override?
		"2. Part B-1: Inheritance, Polymorphism",//no pointers
		"3. Part C-1: Pointers",//pointers
		"4. Exit" };

	do
	{
		Console::Clear();
		menuSelection = Input::GetMenuSelection(menuOptions);
		Console::Clear();

		switch (menuSelection)
		{
		case 1:
		{
			Day7::PartA_1();
			break;
		}
		case 2:
		{
			Day8::PartB_1();
			break;
		}
		case 3:
		{
			Day9::PartC_1();
			break;
		}

		}

		Input::PressEnter();
	} while (menuSelection != menuOptions.size());


	return 0;
}