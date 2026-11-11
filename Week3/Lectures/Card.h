#pragma once
#include <string>
class Card
{

public:

	Card(const std::string& face, const std::string& suit)
		: face_(face), suit_(suit)
	{}

	virtual int Value() const;
	void Print() const;

	const std::string& GetSuit() const { return suit_; }
	void SetSuit(const std::string& suit)
	{
		//validate the parameter before changing the field
		if (suit == "Hearts" || suit == "Diamonds" || 
			suit == "Clubs" || suit == "Spades")
		{
			suit_ = suit;
		}
	}

	const std::string& GetFace() const { return face_; }
	void SetFace(const std::string& face)
	{
		//validate the parameter before changing the field
		if (face == "A" || face == "2" || face == "3" ||
			face == "4" || face == "5" || face == "6" ||
			face == "7" || face == "8" || face == "9" || face == "10"||
			face == "J" || face == "Q" || face == "K")
		{
			face_ = face;
		}
	}

protected:
	std::string face_, suit_;

};

