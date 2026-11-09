#include <iostream>
#include "Console.h"
#include "Day7.h"
#include "Day8.h"
#include "Day9.h"
#include "Input.h"
#include "Player.h"

int main(int argc, char* args[])
{
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