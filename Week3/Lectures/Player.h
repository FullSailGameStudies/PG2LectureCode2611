#pragma once
#include <string>
class Player
{
private:
	//FIELDS
	//what describes the object?
	//different naming conventions:
	// m_sName, mName, _name, name_
	//firstName_  first_name
	std::string name_;
	int level_;

	//METHODS
	//what the object can do?
public:
	//constructors:
	// IF you do not create a ctor, the compiler
	//		will give you a default ctor
	// a default ctor has no parameters
	// IF you do create a ctor, the compiler's default ctor
	//		is not longer available
	//RULES:
	//- must be named the same as the class
	//- there can be NO return type, not even void
	//- can have as many as you need
	//- can have any access modifier
	Player(const std::string& name, int lvl);

	
	//getters and setters can be defined in the header
	// 
	//getters (accessors)
	//return type matches the type of the field
	//no parameters
	//must be const
	const std::string& GetName() const { return name_; }
	int Level() const { return level_; }

	//setters (mutators)
	//return type is void
	//usually a parameter that matches the type of the field
	//cannot be const
	//usually has some validation on the parameter
	void SetName(const std::string& name)
	{
		//validate the parameter before changing the field
		if (name.size() > 0 and name.size() < 32)
		{
			name_ = name;
		}
	}
	void Level(int lvl)
	{
		if (lvl >= 0 && lvl <= 100)
		{
			level_ = lvl;
		}
	}
};

