#ifndef RECIPE_BOOK_H
#define RECIPE_BOOK_H

#include <vector>
#include <string>

using namespace std;

class RecipeBook
{
	public:
	struct Dish
	{
		string dishName;
		vector<string> dishIngrs;
		string dishDesc;
		Dish *next;
		
		Dish() {}
		Dish(string name, vector<string> ingrs, string desc) : dishName(name), dishIngrs(ingrs), dishDesc(desc), next(NULL) {}
	};
	RecipeBook();
	~RecipeBook();
	void addDish(string dish, vector<string> ingrs, string desc);
	void edtDishName(string dish, string newName);
	void edtDishIngr(string dish, vector<string> ingrs);
	void edtDishDesc(string dish, string desc);
	void delDish(string dish);
	void viewDishDetails(string dish);
	void viewAllDishes();
	RecipeBook::Dish* getHead() const;
	
	private:
	int size;
	Dish *head;
	Dish *tail;
	void syncRBook();
};

#endif
