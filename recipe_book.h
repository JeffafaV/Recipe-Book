#ifndef RECIPE_BOOK_H
#define RECIPE_BOOK_H

#include <vector>
#include <string>

// class to hold multiple dishes the same way a cook book would
// class contains a struct Dish that holds all the attributes of 
// a dish and all the functions that can be performed on Dish
class RecipeBook
{
	public:
	// struct to hold all the attributes a dish would have such as 
	// the dish's name, the dish's ingredients, and the dish's recipe
	// each dish will be a node in a singly linked list
	struct Dish
	{
		std::string dishName; // holds the dish name
		std::vector<std::string> dishIngrs; // holds a list of dish ingredients
		std::string dishDesc; // holds the dish recipe/description
		Dish *next; // used to point to the next dish in the linked list
		
		Dish() {} // default constructor
		// parameterized constructor
		Dish(std::string name, std::vector<std::string> ingrs, std::string desc) : dishName(name), dishIngrs(ingrs), dishDesc(desc), next(NULL) {}
	};
	RecipeBook(); // default constructor, will either read or create save file
	~RecipeBook(); // destructor to deallocate memory used for Dish
	void addDish(std::string dish, std::vector<std::string> ingrs, std::string desc); // add a new dish
	void edtDishName(std::string dish, std::string newName); // edit a dish's name
	void edtDishIngr(std::string dish, std::vector<std::string> ingrs); // edit a dish's ingredient list
	void edtDishDesc(std::string dish, std::string desc); // edit a dish's recipe/description
	void delDish(std::string dish); // delete an existing dish
	void viewDishDetails(std::string dish) const; // view a dish's complete content
	void viewAllDishes() const; // view all existing dishes
	RecipeBook::Dish* getHead() const; // get the head or first dish of the linked list
	
	private:
	int size; // holds the size of the linked list
	Dish *head; // points to the first dish in the linked list
	Dish *tail; // points to the last dish in the linked list
	/*maybe should be const*/
	void syncRBook(); // saves all dishes into a save file
};

#endif
