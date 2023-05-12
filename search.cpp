#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "search.h"

Search::Search()
{
	
}

void Search::cookable(const CurrentIngredients &ci, const RecipeBook &rb)
{
	vector<string> cIngrs = ci.getCurrIngr();
	Dish *dish = rb.getHead();
	
	cout << "Cookable dishes:" << endl;
	
	while (dish != NULL)
	{
		if (isSubset(cIngrs, dish->dishIngrs) == true)
		{
			cout << dish->dishName << endl;
		}
		
		dish = dish->next;
	}
}

bool Search::isSubset(vector<string> cIngrs, vector<string> dIngrs)
{
	/* can avoid having to sort cIngrs for every call */
	sort(cIngrs.begin(), cIngrs.end());
	sort(dIngrs.begin(), dIngrs.end());
	
	if (includes(cIngrs.begin(), cIngrs.end(), dIngrs.begin(), dIngrs.end()) == true)
	{
		return true;
	}
	
	return false;
}