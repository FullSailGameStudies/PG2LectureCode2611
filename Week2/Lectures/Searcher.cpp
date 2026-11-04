#include "Searcher.h"

//
// Part B-1
//

int Searcher::LinearSearch(const std::vector<Light>& lights, int greenToFind) const
{
    int index = 0;
	//light is equivalent to lights[i]
	for (auto& light : lights) //foreach or range-based for
	{
		if (light.green == greenToFind)
		{
			return index;
		}
		index++;//adds 1 to index
	}
    return NOT_FOUND;
}
