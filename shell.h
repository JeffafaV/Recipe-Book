#ifndef SHELL_H
#define SHELL_H

#include "current_ingredients.h"
#include "recipe_book.h"
#include "search.h"

class Shell
{
	public:
	Shell();
	// CurrentIngredient interactions
	void addingCIngr();
	void deletingCIngr();
	void viewingCIngr();
	// RecipeBook interactions
	void addingDish();
	void editingDishName();
	void editingDishIngr();
	void editingDishDesc();
	void deletingDish();
	void viewingDishDetails();
	void viewingAllDishes();
	// Search interactions
	void cookableDishes();
	
	private:
	CurrentIngredients ci;
	RecipeBook rb;
	Search srch;
};

#endif
