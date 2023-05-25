#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "current_ingredients.h"

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
	for (int i = 0; i < currIngr.size(); i++)
	{
		if (currIngr[i] == ingr)
		{
			cout << "Ingredient already exists" << endl;
			
			return;
		}
	}
	
	currIngr.push_back(ingr);
	syncCIngr();
}

void CurrentIngredients::delCIngr(string ingr)
{
	for (int i = 0; i < currIngr.size(); i++)
	{
		if (currIngr[i] == ingr)
		{
			currIngr.erase(currIngr.begin()+i);
			syncCIngr();
			return;
		}
	}
	
	cout << "Ingredient doesn't exist" << endl;
}

void CurrentIngredients::viewCIngr() const
{
	cout << "List of currently available ingredients:" << endl;
	
	for (int i = 0; i < currIngr.size(); i++)
	{
		cout << currIngr[i] << endl;
	}
}

void CurrentIngredients::syncCIngr()
{
	ofstream outfile;
	outfile.open("current_ingredients.txt", ofstream::trunc);
	
	for (int i = 0; i < currIngr.size(); i++)
	{
		outfile << currIngr[i] << endl;
	}
	
	outfile.close();
}

vector<string> CurrentIngredients::getCurrIngr() const
{
	return currIngr;
}