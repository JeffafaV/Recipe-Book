#ifndef SEARCH_H
#define SEARCH_H

#include <vector>
#include <string>
#include "current_ingredients.h"
#include "recipe_book.h"

using namespace std;

class Search
{
	private:
	bool isSubset(vector<string> cIngrs, vector<string> dIngrs);
	public:
	Search();
	void cookable(const CurrentIngredients &ci, const RecipeBook &rb);
	/* I might widen the scope of the Search class to show dishes 
	that are missing a few ingredients in case if no dish is cookable */
};

#endif
