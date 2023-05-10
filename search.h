#ifndef SEARCH_H
#define SEARCH_H

#include "current_ingredients.h"
#include "recipe_book"
#include <vector>

using namespace std;

class Search
{
	public:
	Search();
	vector<int> cookable(const CurentIngredients& ci, const RecipeBook& rb);
};

#endif
