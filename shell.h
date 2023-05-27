#ifndef SHELL_H
#define SHELL_H

#include "current_ingredients.h"
#include "recipe_book.h"
#include "search.h"

// class to act like a shell program so the user can interact
// with the different parts of the cook book and its functions
class Shell
{
	public:
	Shell(); // empty default constructor
	// CurrentIngredients interactions
	void addingCIngr(); // adds ingredient to the available ingredient list
	void deletingCIngr(); // deletes an ingredient from the available ingredient list
	void viewingCIngr(); // displays all ingredients from the available ingredient list
	// RecipeBook interactions
	void addingDish(); // adds a new dish to the the cook book
	void editingDishName(); // edits a dish's name from the cook book
	void editingDishIngr(); // edits a dish's ingredient list from the cook book
	void editingDishDesc(); // edits a dish's description/recipe from the cook book
	void deletingDish(); // deletes a dish from the cook book
	void viewingDishDetails(); // displays a dish's complete content from the cook book
	void viewingAllDishes(); // displays all the dish's in the cook book
	// Search interactions
	void cookableDishes(); // displays all preparable dishes
	
	private:
	// no need to initialize these in the default 
	// constructor since they initialize themselves
	CurrentIngredients ci; // object for CurrentIngredients
	RecipeBook rb; // object for RecipeBook
	Search srch; // object for Search
};

#endif
