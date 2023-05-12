#ifndef SEARCH_H
#define SEARCH_H

#include <vector>
#include <string>
#include "current_ingredients.h"
#include "recipe_book"

using namespace std;

class Search
{
	private:
	bool isSubset(vector<string> cIngrs, vector<string> dIngrs);
	public:
	Search();
	void cookable(const CurentIngredients &ci, const RecipeBook &rb);
};

#endif
