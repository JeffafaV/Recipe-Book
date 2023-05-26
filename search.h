#ifndef SEARCH_H
#define SEARCH_H

#include <vector>
#include <string>
#include "current_ingredients.h"
#include "recipe_book.h"

// class to perform dish searches by comparing the current ingredients 
// with each dish's ingredients to find all cookable/preparable dishes
class Search
{
	private:
	bool isSubset(std::vector<std::string> cIngrs, std::vector<std::string> dIngrs); // checks if dish is preparable by comparing ingredients
	public:
	Search(); // empty default constructor
	void cookable(const CurrentIngredients &ci, const RecipeBook &rb); // prints a list of all preparable dishes
	/* I might widen the scope of the Search class to show dishes 
	that are missing a few ingredients in case if no dish is cookable */
};

#endif
