#ifndef CURRENT_INGREDIENTS_H
#define CURRENT_INGREDIENTS_H

#include <vector>
#include <string>

using namespace std;

class CurrentIngredients
{
	private:
	vector<string> currIngr;
	void syncCIngr();
	
	public:
	CurrentIngredients();
	void addCIngr(string ingr);
	void delCIngr(string ingr);
	void viewCIngr(string ingr);
};

#endif
