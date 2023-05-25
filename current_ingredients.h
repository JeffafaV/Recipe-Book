#ifndef CURRENT_INGREDIENTS_H
#define CURRENT_INGREDIENTS_H

#include <vector>
#include <string>

// class to hold the currently available ingredients the user inputs
// as well as all the functions that can be performed on it
class CurrentIngredients
{
	private:
	std::vector<std::string> currIngr; // holds all the currently available ingredients
	void syncCIngr(); // saves currIngr into a save file
	
	public:
	CurrentIngredients(); // default constructor, will either read or create save file
	void addCIngr(std::string ingr); // add ingredient to currIngr
	void delCIngr(std::string ingr); // delete ingredient from currIngr
	void viewCIngr() const; // prints all ingredients in currIngr
	std::vector<std::string> getCurrIngr() const; // currIngr getter function
};

#endif
