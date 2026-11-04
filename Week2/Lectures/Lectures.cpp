#include <iostream>
#include "Console.h"
#include "Day4.h"
#include "Day5.h"
#include "Day6.h"
#include <Input.h>
#include <map>


void NamedBlockOfCode(int param)
{
	//ALL recursive functions REQUIRE an EXIT condition (base case)
	//a way to exit the function
	//exit conditions can be true or false
	//you must have 1 or more exit conditions
	//you must have 1 or more recursive cases
	if(param < 100) //loop while this condition is true
	{
		std::cout << param << "\n";
		NamedBlockOfCode(param + 1);//recursive case (causes a loop)
		Console::WriteLine(param, ConsoleColor::Green);
	}
}

void PrintWithIterator(const std::map<std::string, float>& menu)
{
	std::cout << "\n Bob's Burgers (iterators)\n";
	for (auto it = menu.begin(); it != menu.end(); it++)
	{
		//it "points" to a key-value-pair object
		//use ->first and ->second to access the parts of the pair
		std::cout << (*it).first << " " << it->second << "\n";
	}
}

void PrintWithForeach(const std::map<std::string, float>& menu)
{
	std::cout << "\n Bob's Burgers (foreach)\n";
	for (auto& kvp : menu)
	{
		std::cout << kvp.first << " " << kvp.second << "\n";
	}
}
void PrintWithStructuredBindings(const std::map<std::string, float>& menu)
{
	std::cout << "\n Bob's Burgers (Structured Bindings)\n";
	for (auto& [itemName,itemPrice] : menu)
	{
		std::cout << itemName << " " << itemPrice << "\n";
	}
}

int main(int argc, char* args[])
{
	NamedBlockOfCode(1);
	srand(static_cast<unsigned int>(time(NULL)));

	std::string hello = "Hello Week 2!";
	for (auto& ch : hello)
	{
		Console::Write(ch, (ConsoleColor)(rand() % 7 + 1));
	}
	std::cout << "\n";

	std::map<std::string, float> menu;

	//how to add items to a map:
	//1) "easy" way  map[key] = value;
	menu["Cheese Burger"] = 8.99f;
	menu["French Fries"] = 4.50f;
	menu["French Fries"] = 3.50f;//overwrites the value

	//2) "not-as-easy" way map.insert(key-value pair);
	std::pair< std::string, float> kvp =
		std::make_pair("Special Sauce",0.50f);
	menu.insert(kvp);//tries to insert into the map

	//std::pair have 2 members: first and second
	kvp.second = 0.25f;
	//tries to insert into the map
	auto itemInserted = menu.insert(kvp);
	//will NOT overwrite
	if (!itemInserted.second)
	{
		std::cout << kvp.first << " is already on the menu. Do you want to change the price?\n";
	}
	std::string menuItem = "Special Sauce";
	//looks up the key and returns the value
	float itemPrice = menu[menuItem];
	std::cout << menuItem << " costs " << itemPrice << "\n";

	menuItem = "Dino Nuggs";
	//if it doesn't find it, it adds it!!!!
	//itemPrice = menu[menuItem];
	//std::cout << menuItem << " costs " << itemPrice << "\n";
	//use "find" to lookup the key
	//find returns an iterator!
	//tries to find the key
	//	returns an iterator to the found item
	//  OR, 
	//  if it doesn't find it, it returns the end() of the map
	auto menuItemIterator = menu.find(menuItem);
	if (menuItemIterator != menu.end())
		std::cout << menuItem << " costs " << menuItemIterator->second << "\n";
	else
		std::cout << menuItem << " is not on the menu! Go to McDonald's\n";

	menuItem = "Special Sauce"; 
	menuItemIterator = menu.find(menuItem);
	if (menuItemIterator != menu.end())
	{
		float oldPrice = menuItemIterator->second;
		std::cout << menuItem << " used to costs " << oldPrice << "\n";
		//update the value in the map
		//1) use the map[key] = newValue;
		//2) if you have an iterator, use the iterator->second = newValue;
		//menuItemIterator->first = "Secret Sauce";
		menuItemIterator->second *= 1.10f;
		std::cout << "Now it costs " << menuItemIterator->second << "!!!\n";
	}

	PrintWithIterator(menu);
	PrintWithForeach(menu);
	PrintWithStructuredBindings(menu);

	int menuSelection = 0;
	std::vector<std::string> menuOptions{
		"1. Recursion Example\n",
		"2. Part A-1.1: Recursion (Bats)",
		"3. Part A-1.2: Recursion (Reverse Word)",
		"4. Part A-1.3: Recursion (Reverse words in a sentence)\n",
		"5. Part A-2: Sorting\n",
		"6. Part B-1: Linear Search\n",
		"7. Part B-2: Maps",
		"8. Part B-3: Find in Maps",
		"9. Part C-1: Erase from Maps",
		"10. Exit" };


	do
	{
		Console::Clear();
		menuSelection = Input::GetMenuSelection(menuOptions);
		Console::Clear();

		switch (menuSelection)
		{
		case 1:
		{
			Day4::RecursionExample();
			break;
		}
		case 2:
		{
			Day4::PartA_1_1();
			break;
		}
		case 3:
		{
			Day4::PartA_1_2();
			break;
		}
		case 4:
		{
			Day4::PartA_1_3();
			break;
		}
		case 5:
		{
			Day4::PartA_2();
			break;
		}
		case 6:
		{
			Day5::PartB_1();
			break;
		}
		case 7:
		{
			Day5::PartB_2(1);
			break;
		}
		case 8:
		{
			Day5::PartB_2(2);
			break;
		}
		case 9:
		{
			Day6::PartC_1();
			break;
		}

		}

		Input::PressEnter();
	} while (menuSelection != menuOptions.size());

	return 0;
}