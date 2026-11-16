#include <iostream>
#include "Console.h"
#include "Day10.h"
#include "Day11.h"
#include "Input.h"
#include <filesystem>

//give a namespace a new name
namespace fs = std::filesystem;

void ShowFilesByExtension(const std::string& path, const std::string& ext)
{
	for (const auto& entry : fs::directory_iterator(path)) 
	{
		if (fs::is_regular_file(entry) && 
			entry.path().extension() == ext)
		{
			std::cout << entry.path() << '\n';
		}
	}
}

int main(int argc, char* args[])
{
	std::string path = "C:/temp/2611/";
	std::string fileName = "2611.csv";
	std::string finalPath = path + fileName;

	std::cout << fs::exists(".") << "\n";
	ShowFilesByExtension(".", ".cpp");

	for (const auto& entry : fs::directory_iterator(".")) {
		if (fs::is_directory(entry))
		{
			std::cout << "DIRECTORY: ";
		}
		else if (fs::is_regular_file(entry))
		{
			std::cout << "REGULAR: ";
			std::cout << entry.path().extension() << " ";
			std::cout << entry.path().filename() << " ";
		}
		std::cout << entry.path() << '\n';
	}

    std::string hello = "Hello Week 4!";
    for (auto& ch : hello)
    {
        Console::Write(ch, (ConsoleColor)(rand() % 7 + 1));
    }
    std::cout << "\n";

	int menuSelection = 0;
	std::vector<std::string> menuOptions{
		"1. Part A-1: Read CSV file",
		"2. Part A-2: Write CSV file",
		"3. Part B: Serialize/Deserialize objects",
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
			Day10::PartA_1();
			break;
		}
		case 2:
		{
			Day10::PartA_2();
			break;
		}
		case 3:
		{
			Day11::PartB();
			break;
		}

		}

		Input::PressEnter();
	} while (menuSelection != menuOptions.size());

	return 0;
}