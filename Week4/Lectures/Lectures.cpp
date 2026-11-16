#include <iostream>
#include "Console.h"
#include "Day10.h"
#include "Day11.h"
#include "Input.h"
#include <filesystem>
#include <fstream> //fstream, ofstream, ifstream
#include <sstream> //stringstream
#include <Player.h>

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
	//3 basic steps:
	//1) Open the file. DUH!!
	//	- this could fail for many reasons
	//	- you have to know the path
	//	- you have to know the mode of opening the file
	//2) write/read the file
	//3) CLOSE the file!! 
	//	- files are SYSTEM resources
	//	- close the files ASAP!

	std::string path = "C:/temp/2611/";
	path = "./";
	std::string fileName = "2611.csv";
	std::string finalPath = path + fileName;
	//the path MUST exists. this process will NOT create the path.
	//if the path exists, this will create the file
	//IF you have permission to write to that path
	std::ofstream outFile(finalPath);
	//ALWAYS check if it worked
	//1) open the file
	char delimiter = '^';
	if (outFile.is_open())
	{
		//2) write the file
		// << - insertion operator
		// >> - extraction operator
		outFile << "Batman is better than EVERY super." << delimiter << 5;
		outFile << delimiter << true << delimiter << 12.7;
		outFile << delimiter << "Aquaman smells like fish.";

	}
	else
	{
		std::cout << finalPath << " could not be opened.\n";
	}
	//3) close the file
	outFile.close();

	//READ the file
	std::ifstream inFile(finalPath);
	if (inFile.is_open())
	{
		//read the line
		std::string line;
		//reads the STREAM until it reaches a \n 
		//OR the end of the stream
		std::getline(inFile, line);
		std::cout << line << "\n";

		//parse the line
		//convert the string to a STREAM
		std::stringstream lineStream(line);
		std::string data;
		//reads the STREAM until it reaches a delimiter OR
		//the end of the stream
		std::getline(lineStream, data, delimiter);
		std::cout << data << "\n";

		std::getline(lineStream, data, delimiter);
		int iData = std::stoi(data);
		std::cout << iData << "\n";

		//lookup try-catch
		std::getline(lineStream, data, delimiter);
		try
		{
			bool bData = std::stoi(data);
			std::cout << bData << "\n";
		}
		catch (const std::exception&)
		{

		}
		std::getline(lineStream, data, delimiter);
		double dData = std::stod(data);
		std::cout << dData << "\n";

		std::getline(lineStream, data, delimiter);
		std::cout << data << "\n";
	}
	else
	{
		std::cout << finalPath << " could not be opened.\n";
	}
	//3) close the file
	inFile.close();


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

	Player p1;
	fileName = "playerOne.csv";
	std::ofstream oFile(fileName);
	if (oFile.is_open())
	{
		p1.SerializeCSV(oFile, '$');
		oFile << "\n";
		p1.SerializeCSV(oFile, '$');
		oFile << "\n";
		p1.SerializeCSV(oFile, '$');
	}
	else
	{
		std::cout << fileName << " could not be opened.\n";
	}
	//3) close the file
	oFile.close();

	std::ifstream iFile(fileName);
	if (iFile.is_open())
	{
		std::string line;
		while (not iFile.eof())//end of file
		{
			std::getline(iFile, line);//read the line from the file
			Player p2(line, '$');
		}
	}
	else
	{
		std::cout << fileName << " could not be opened.\n";
	}
	//3) close the file
	iFile.close();




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