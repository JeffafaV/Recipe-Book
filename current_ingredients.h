#ifndef CURRENT_INGREDIENTS_H
#define CURRENT_INGREDIENTS_H

#include <vector>

using namespace std;

class CurrentIngredients
{
	private:
	vector<int> curr_ingr;
	void syncCIngr();
	
	public:
	CurrentIngredients();
	void addCIngr();
	void delCIngr();
	void viewCIngr();
};

#endif
