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
			
			// when the heap is full it sets the pointer that tries to allocate memory to null
			if (t == NULL)
			{
				cout << "No more memory left to store dish" << endl;
				return;
			}
			
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
			// stores the remaining third section (dish description) in the node
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
	Dish *t = head;
	
	while (t != NULL)
	{
		if (t->dishName == dish)
		{
			cout << "Dish already exists" << endl;
			return;
		}
	}
	
	Dish *newDish = new Dish(dish, ingrs, desc);
	
	// when the heap is full it sets the pointer that tries to allocate memory to null
	if (newDish == NULL)
	{
		cout << "No more memory left to store dish" << endl;
		return;
	}
	
	if (tail == NULL)
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
	syncRBook();
}

void RecipeBook::edtDishName(string dish, string newName)
{
	Dish *t = head;
	
	while (t != NULL)
	{
		if (t->dishName == dish)
		{
			t->dishName = newName;
			syncRBook();
			return;
		}
		
		t = t->next;
	}
	
	cout << "Dish does not exist" << endl;
}

void RecipeBook::edtDishIngr(string dish, vector<string> ingrs)
{
	Dish *t = head;
	
	while (t != NULL)
	{
		if (t->dishName == dish)
		{
			t->dishIngrs = ingrs;
			syncRBook();
			return;
		}
		
		t = t->next;
	}
	
	cout << "Dish does not exist" << endl;
}

void RecipeBook::edtDishDesc(string dish, string desc)
{
	Dish *t = head;
	
	while (t != NULL)
	{
		if (t->dishName == dish)
		{
			t->dishDesc = desc;
			syncRBook();
			return;
		}
		
		t = t->next;
	}
	
	cout << "Dish does not exist" << endl;
}

void RecipeBook::delDish(string dish)
{
	Dish *t1 = head;
	Dish *t2 = NULL;
	int index = -1;
	
	while (t1 != NULL)
	{
		index++;
		
		if (t1->dishName == dish)
		{
			if (index > 0)
			{
				t2->next = t1->next;
				delete t1;
				t1 = NULL;
				
				if (index == size-1)
				{
					tail = t2;
				}
			}
			else
			{
				Dish *initial = head;
				head = head->next;
				
				if (initial == tail)
				{
					tail = head;
				}
				
				delete initial;
			}
			
			size--;
			syncRBook();
			return;
		}
		
		t2 = t1;
		t1 = t1->next;
	}
	
	cout << "Dish does not exist" << endl;
}

void RecipeBook::syncRBook()
{
	ofstream outfile;
	outfile.open("recipe_book.txt", ofstream::trunc);
	
	Dish *t = head;
	
	while (t != NULL)
	{
		outfile << t->dishName << "*";
		
		for (int i = 0; i < t->dishIngrs.size(); i++)
		{
			outfile << t->dishIngrs[i] << ",";
		}
		
		outfile << "*" << t->dishDesc << endl;
		
		t = t->next;
	}
	
	outfile.close();
}

void RecipeBook::viewDishDetails(string dish)
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

RecipeBook::Dish* RecipeBook::getHead()
{
	return head;
}