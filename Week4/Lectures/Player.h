#pragma once
#include <fstream>
#include <string>

class Player
{
public:

	Player() : worldX(0), worldY(0) {}

	//
	// Part B-1.1
	//

	//
	// Part B-2.1
	//
	
	//
	// Part B-2.3
	//


	void MoveLeft() { worldX--; }
	void MoveRight() { worldX++; }
	void MoveUp() { worldY--; }
	void MoveDown() { worldY++; }

	void GetPosition(int& x, int& y)
	{
		x = worldX;
		y = worldY;
	}

	void SerializeCSV(std::ofstream& file, char delimiter) const;

	//ctor that calls deserialize
	Player(const std::string& line, char delimiter)
	{
		DeserializeCSV(line, delimiter);
	}
	//deserialize to parse the string
	void DeserializeCSV(const std::string& line, char delimiter);


	void Info();
private:
	int worldX, worldY;
};

