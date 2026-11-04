#pragma once
#include <vector>
#include "Light.h"

const int NOT_FOUND = -1;

class Searcher
{
public:
	/// <summary>
	/// Linearly search the vector for a light that has the same green value as the parameter
	/// </summary>
	/// <param name="lights">the vector to search</param>
	/// <param name="greenToFind">the green value to search for</param>
	/// <returns>
	/// the index of the light if a match is found.
	/// if not found, it returns NOT_FOUND (-1)
	/// </returns>
	int LinearSearch(const std::vector<Light>& lights, int greenToFind) const;
};

