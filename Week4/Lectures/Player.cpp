#include "Player.h"
#include "Console.h"
#include <iomanip>
#include <sstream>

//
// Part B-1.2
//

//
// Part B-2.2
//

void Player::SerializeCSV(std::ofstream& file, char delimiter) const
{
	file << worldX << delimiter << worldY;
}

void Player::DeserializeCSV(const std::string& line, char delimiter)
{
	std::stringstream lineStream(line);
	std::string data;
	std::getline(lineStream, data, delimiter);
	worldX = std::stoi(data);

	std::getline(lineStream, data, delimiter);
	worldY = std::stoi(data);
}

void Player::Info()
{
	Console::SetCursorPosition(0, 12);
	std::cout << "POSITION: " << std::setw(7) << std::right << worldX << "," << worldY;
}