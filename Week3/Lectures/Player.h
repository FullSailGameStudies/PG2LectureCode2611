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
	//getters and setters can be defined in the header
	// 
	//getters (accessors)
	//return type matches the type of the field
	//no parameters
	//must be const
	const std::string& GetName() const { return name_; }

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
};

