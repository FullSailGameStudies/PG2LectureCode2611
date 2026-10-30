#include "Day1.h"
#include "Day2.h"
#include "Day3.h"
#include <Console.h>
#include <Input.h>

//int Factor(int num)//pass by value (COPY)
//{
//	num *= 3;
//	return num;
//}
//PASS BY REFERENCE:
//when to use:
//  1) another scope needs to access my variable
//  2) prevent a copy (performance)

//my RULES: 
//  if the parameter is a class, pass by ref
//  if I want the function to update my variable, pass by ref
void Factor(int& num)//pass by ref (ALIAS)
{
	num *= 3;
}

const float PI = 3.1415f;

void Stats(const std::vector<int>& numbers, int& avg, int& min, int& max)
{
	int sum = 0;
	min = INT_MAX;
	max = INT_MIN;
	//range-base (foreach)
	for (auto& number : numbers)
	{
		sum += number;
		if (number < min) min = number;
		max = std::max(max, number);
	}
	avg = sum / numbers.size();
}
void Print(const std::vector<int>& nums, int top = 0)
{
	for (int i = 0; i < nums.size(); i++)
	{
		std::cout << nums[i] << " ";
	}
	std::cout << "\n";
}
void Info(const std::vector<int>& nums)
{
	//size() - how many items in the vector
	//capacity() - how big the internal array is
	//size <= capacity
	//when size = capacity AND you add a new item, it must 
	//resize the internal array
	std::cout << nums.size() << "/" << nums.capacity() << "\n";
}
int main(int argc, char* args[])
{
	Day2 day2;
	std::vector<int> nummies{ 2,2,1,3,2,2,2,4 };
	//an iterator is an OBJECT that "points" to
	//an item in the container
	//it knows how to move through the container
	//iterator functions:
	// vector.begin() - iterator to the first item
	// vector.end() - iterator to the item AFTER the last item??????????
	//nummies.erase(2);//erase requires an iterator
	for (std::vector<int>::iterator it = nummies.begin(); it != nummies.end(); it++)
	{
		//"dereference" the iterator with `*`
		std::cout << *it << "\n";
	}
	//need an iterator to '1' which is the 2 index
	//begin() + index
	nummies.erase(nummies.begin() + 2);
	//{ 2,2,3,2,2,2,4,4 }
	Print(nummies);
	for (int i = 0; i < nummies.size(); i++)
	{
		if (nummies[i] == 2)
		{
			nummies.erase(nummies.begin() + i);
			i--;//when erasing, decrement i
		}
	}
	//OR...
	for (int i = 0; i < nummies.size(); )
	{
		if (nummies[i] == 2)
		{
			nummies.erase(nummies.begin() + i);
		}
		else
			i++;//only increment when you don't erase
	}
	//OR...
	//reverse for loop
	for (int i = nummies.size() - 1; i >= 0; i--)
	{
		if (nummies[i] == 2)
		{
			nummies.erase(nummies.begin() + i);
		}
	}
	Print(nummies);

	std::vector<int> v2 = nummies;

	auto v3(nummies);
	//{0,1,2,3}
	//{0,1,2,3,4}
	std::vector<int> v4;
	v4.reserve(10);//sets the capacity
	Info(v4);// 0 / 0 ?  0 / 1? 0 / 1000?
	for (int i = 0; i < 10; i++)
	{
		v4.push_back(rand());
		Info(v4);
	}


	/*for (int i = 0; i < 100; i++)
	{
		nummies.push_back(rand());
	}*/
	int average, minimum, maximum;
	Stats(nummies, average, minimum, maximum);
	std::cout << "Average: " << average << "\tMinimum: " << minimum;
	std::cout << "\tMaximum: " << maximum << "\n";

	int nummy = 5;
	Factor(nummy);
	int& numRef = nummy;
	numRef += 5;
	std::cout << nummy << "\n";

	//capturing the return value
	int width = Console::GetWindowWidth();

	int menuSelection = 0;
	std::vector<std::string> menuOptions{
		"1. Part A-1.0: Calling static methods",
		"2. Part A-1.1: calling non-static methods",
		"3. Part A-1.2: calling non-static methods",
		"4. Part A-1.3: calling non-static methods",
		"5. Part A-1.4: Return Values",
		"6. Part A-1.5: Passing arguments",
		"7. Part A-2: Creating methods\n",
		"8. Part B-1: Pass by reference",
		"9. Part B-2: Const",
		"10. Part B-3: Erasing in a loop\n",
		"11. Part C-1: Default Parameters",
		"12. Part C-2: Copying Vectors\n",
		"13. Exit" };


	do
	{
		Console::Clear();
		menuSelection = Input::GetMenuSelection(menuOptions);
		Console::Clear();

		switch (menuSelection)
		{
		case 1:
		{
			//
			// part A-1.0: calling methods on the Console class to print messages.
			//
			//	Use Console::Write and Console::WriteLine to print several lines of text (whatever you want to say)
			//  Experiment with changing the colors.
			//  Open the Console.h file (look in Misc/Console in Solution Explorer) to see how the methods are declared.
			//
			Console::Write("Batman is AWESOME!");
			Console::WriteLine("\tAquaman smells like fish.", ConsoleColor::Green);
			Console::WriteLine("Superman is an ALIEN!", ConsoleColor::Red);
			break;
		}
		case 2:
		{
			Day1::PartA_1_1();
			break;
		}
		case 3:
		{
			Day1::PartA_1_2();
			break;
		}
		case 4:
		{
			Day1::PartA_1_3();
			break;
		}
		case 5:
		{
			//
			// part A-1.4: Getting return values
			//	Ask the user to enter their name. Print the name.
			// 
			//	Open Lectures.cpp.
			//	Add code here to call Input::GetString.
			//	Store the result in a string variable.
			//	Print the name that the user enters.
			//	Open the Input.h file(look in Misc / Input in Solution Explorer) to see how the GetString is declared.
			//
			break;
		}
		case 6:
		{
			//
			// part A-1.5: passing arguments
			//	Ask the user for their age. A minimum age would be 0 and a maximum age would be 120.
			// 
			//	Open Lectures.cpp.
			//	Add code here to call Input::GetInteger.
			//	Store the result in an int variable.
			//	Print the age that the user enters.
			//	Open the Input.h file(look in Misc / Input in Solution Explorer) to see how the GetInteger is declared.
			//
			int age = Input::GetInteger("What is your age?", 0, 120);
			Console::Write("Your age is ");
			Console::WriteLine(age, ConsoleColor::Yellow, ConsoleColor::Cyan);
			break;
		}
		case 7:
		{
			Day1::PartA_2();
			break;
		}
		case 8:
		{
			day2.PartB();
			break;
		}
		case 9:
		{
			day2.PartB(2);
			break;
		}
		case 10:
		{
			day2.PartB(3);
			break;
		}
		case 11:
		{
			Day3::PartC_1();
			break;
		}
		case 12:
		{
			Day3::PartC_2();
			break;
		}
		}

		Input::PressEnter();
	} while (menuSelection != menuOptions.size());

	return 0;
}

