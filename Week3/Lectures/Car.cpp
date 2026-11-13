#include "Car.h"


//initialize explicitly using the class name scoping
int Car::mNumberOfCarsMade = 0;


//non-static functions:
//there is a hidden parameter called 'this'
//'this' is the POINTER to the object 
// that the function was called on
//non-static functions can access non-static members
//  AND static members
std::string Car::vehicleInformation()
{
	return std::to_string(this->mModelYear) + " " + mMake + " " + mModel;
}
