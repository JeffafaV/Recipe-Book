#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "recipe_book.h"

using namespace std;

RecipeBook::RecipeBook()
{
	size = 0;
	head = NULL;
	tail = NULL;
	
	fstream file;
	file.open("recipe_book.txt");
	
	if (!file.good())
	{
		ofstream("recipe_book.txt");
	}
	else
	{
		ifstream readfile;
		readfile.open("recipe_book.txt");
		string dishData;
		
		while (getline(readfile, dishData))
		{
			Dish *t = new Dish;
			int asteriskPos;
			int commaPos;
			string ingrList;
			string singleIngr;
			
			asteriskPos = dishData.find('*');
			t->dishName = dishData.substr(0, asteriskPos);
			dishData = dishData.substr(asteriskPos+1);
			asteriskPos = dishData.find('*');
			ingrList = dishData.substr(0, asteriskPos);
			//dishData = dishData.substr(asteriskPos+1);
			
			while (!ingrList.empty())
			{
				commaPos = ingrList.find(',');
				singleIngr = ingrList.substr(0, commaPos);
				t->dishIngrs.push_back(singleIngr);
				ingrList = ingrList.substr(commaPos+1);
			}
			
			dishData = dishData.substr(asteriskPos+1);
			t->dishDesc = dishData;
			t->next = NULL;
			
			if (head == NULL)
			{
				head = t;
				tail = t;
			}
			else
			{
				tail->next = t;
				tail = t;
			}
			
			size++;
		}
	}
}

RecipeBook::~RecipeBook()
{
	Dish *t = head;
	
	while (head != NULL)
	{
		head = head->next;
		delete t;
		t = head;
	}
}

void RecipeBook::addDish(string dish, vector<string> ingrs, string desc)
{
	
}

void RecipeBook::edtDishName(string dish, string newName)
{
	
}

void RecipeBook::edtDishIngr(string dish, vector<string> ingrs)
{
	
}

void RecipeBook::edtDishDesc(string dish, string desc)
{
	
}

void RecipeBook::delDish(string dish)
{
	
}

void RecipeBook::syncRBook()
{
	
}