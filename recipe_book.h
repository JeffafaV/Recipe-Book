#ifndef RECIPE_BOOK_H
#define RECIPE_BOOK_H

#include <vector>
#include <string>

using namespace std;

class RecipeBook
{
	private:
	struct Dish
	{
		string dishName;
		vector<string> dishIngrs;
		string dishDesc;
		Dish *next;
		
		Dish() {}
		Dish(string name, vector<string> ingrs, string desc) : dishName(name), dishIngrs(ingrs), dishDesc(desc), next(NULL) {}
	};
	
	int size;
	Dish *head;
	Dish *tail;
	void syncRBook();
	
	public:
	RecipeBook();
	~RecipeBook();
	void addDish(string dish, vector<string> ingrs, string desc);
	void edtDishName(string dish, string newName);
	void edtDishIngr(string dish, vector<string> ingrs);
	void edtDishDesc(string dish, string desc);
	void delDish(string dish);
	void viewDishDetails(string dish);
	void viewAllDishes();
	Dish* getHead();
};

#endif
