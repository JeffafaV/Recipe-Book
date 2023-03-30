#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

CurrentIngredients::CurrentIngredients()
{
	fstream file;
	file.open("current_ingredients.txt");
	
	if (!file.good())
	{
		ofstream("current_ingredients.txt");
	}
	else
	{
		ifstream readfile;
		readfile.open("current_ingredients.txt");
		string ingr;
		
		while (getline(readfile, ingr))
		{
			currIngr.push_back(ingr);
		}
		
		readfile.close();
	}
	
	file.close();
}

void CurrentIngredients::addCIngr(string ingr)
{
	
}

void CurrentIngredients::delCIngr(string ingr)
{
	
}

void CurrentIngredients::viewCIngr(string ingr)
{
	
}

void CurrentIngredients::syncCIngr()
{
	
}