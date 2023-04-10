#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "recipe_book.h"

using namespace std;

RecipeBook::RecipeBook()
{
	// setting default values
	size = 0;
	head = NULL;
	tail = NULL;
	
	// opening file
	fstream file;
	file.open("recipe_book.txt");
	
	// file does not exist
	if (!file.good())
	{
		ofstream("recipe_book.txt");
	}
	// file exists
	else
	{
		// open file in reading mode
		ifstream readfile;
		readfile.open("recipe_book.txt");
		
		// stores the entire line of data of a dish
		string dishData;
		
		// loop through all entries (dishes) of the file
		while (getline(readfile, dishData))
		{
			// create new dish node
			Dish *t = new Dish;
			
			// used to hold string positions in order
			// to cut string dishData into desired chunks
			int asteriskPos;
			int commaPos;
			
			// used to get and store the ingredients of the dish
			string ingrList;
			string singleIngr;
			
			// used to get the first section of the dish data (dish name)
			asteriskPos = dishData.find('*');
			// stores the dish name in the node
			t->dishName = dishData.substr(0, asteriskPos);
			// cut the dish name from the dish data
			dishData = dishData.substr(asteriskPos+1);
			
			// used to get the second section of the dish data(dish ingredients)
			asteriskPos = dishData.find('*');
			// saves the ingredient list into a string
			ingrList = dishData.substr(0, asteriskPos);
			
			// continue looping until ingrList has no more ingredients
			while (!ingrList.empty())
			{
				// used to get the first ingredient in the list
				commaPos = ingrList.find(',');
				// saves the first ingredient into a string
				singleIngr = ingrList.substr(0, commaPos);
				// stores the ingredient into the node's vector
				t->dishIngrs.push_back(singleIngr);
				// cut the first ingredient from the list
				ingrList = ingrList.substr(commaPos+1);
			}
			
			// cuts the dish ingredients from the the dish data
			dishData = dishData.substr(asteriskPos+1);
			// remaining data is the dish description
			t->dishDesc = dishData;
			
			t->next = NULL;
			
			// node is the first node in the linked list
			if (head == NULL)
			{
				head = t;
				tail = t;
			}
			// node is not the first node in the linked list
			else
			{
				tail->next = t;
				tail = t;
			}
			
			// increment linked list size
			size++;
		}
	}
}

RecipeBook::~RecipeBook()
{
	// temp pointer pointing at head
	Dish *t = head;
	
	// delete each node in the linked list
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
	Dish *t = head;
	
	while (t != NULL)
	{
		
}

void RecipeBook:viewDishDetails(string dish)
{
	// temp pointer used to traverse linked list
	Dish *t = head;
	
	// traverse the link list
	while (t != NULL)
	{
		// dish was found
		// print all dish details
		if (t->dishName == dish)
		{
			cout << "Dish Name:" << endl;
			cout << t->dishName << endl << endl;
			cout << "Ingredients:" << endl;
			for (int i = 0; i < t->dishIngrs.size(); i++)
			{
				cout << t->dishIngrs[i] << endl;
			}
			cout << endl;
			cout << "Description:" << endl;
			cout << t->dishDesc << endl << endl;
			
			return;
		}
	}
	
	// dish was not present
	cout << "Dish does not exist in recipe book" << endl << endl;
}

void RecipeBook::viewAllDishes()
{
	// used to traverse linked list
	Dish *t = head;
	
	// loop through entire linked list
	// print each dish name
	while (t != NULL)
	{
		cout << t->dishName << endl;
		t = t->next;
	}
}