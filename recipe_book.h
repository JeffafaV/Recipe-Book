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
		vector<string> dishIngr;
		string dishDesc;
		Dish *next;
		
		Dish(string name) : dishName(name), next(NULL) {}
	};
	
	int size;
	Dish *head;
	Dish *tail;
	void syncRBook;
	
	public:
	RecipeBook();
	~RecipeBook();
	void addDishName(int index, string name);
	void addDishIngr(int index, vector<string> ingr);
	void addDishDesc(int index, string desc);
	void edtDishName(int index, string name);
	void edtDishIngr(int index, vector<string> ingr);
	void edtDishDesc(int index, string desc);
	void delDish(int index);
};

#endif
