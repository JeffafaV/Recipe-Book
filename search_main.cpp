#include <iostream>
#include <string>
#include <vector>
#include "recipe_book.h"
#include "current_ingredients.h"
#include "search.h"

using namespace std;

int main()
{
	RecipeBook rb;
	CurrentIngredients ci;
	Search srch;
	
	bool exit = false;
	
	while (exit == false)
	{
		int menuChoice;
		string dish;
		string newName;
		string ingr;
		vector<string> ingrs;
		string desc;
		
		cout << "1 to add ingredient" << endl;
		cout << "2 to delete ingredient" << endl;
		cout << "3 to view all ingredients" << endl;
		cout << "4 to add dish" << endl;
		cout << "5 to delete dish" << endl;
		cout << "6 to edit dish name" << endl;
		cout << "7 to edit dish ingredients" << endl;
		cout << "8 to edit dish description" << endl;
		cout << "9 to view dish details" << endl;
		cout << "10 to view all dishes" << endl;
		cout << "11 to search for preparable dishes" << endl;
		cin >> menuChoice;
		cin.ignore();
		
		switch (menuChoice)
		{
			case 1:
			{
				cout << "Enter ingredient to add" << endl;
				getline(cin, ingr);
				ci.addCIngr(ingr);
				break;
			}
			case 2:
			{
				cout << "Enter ingredient to delete" << endl;
				getline(cin, ingr);
				ci.delCIngr(ingr);
				break;
			}
			case 3:
			{
				ci.viewCIngr();
				break;
			}
			case 4:
			{
				cout << "Enter dish to add" << endl;
				getline(cin, dish);
				
				cout << "Enter dish ingredient. Enter quit to stop" << endl;
				getline(cin, ingr);
				
				//ingrs.clear();
				while (ingr != "quit")
				{
					ingrs.push_back(ingr);
					cout << "Enter dish ingredient. Enter quit to stop" << endl;
					getline(cin, ingr);
				}
				
				cout << "Enter dish description/recipe" << endl;
				getline(cin, desc);
				
				rb.addDish(dish, ingrs, desc);
				break;
			}
			case 5:
			{
				cout << "Enter dish to delete" << endl;
				getline(cin, dish);
				
				rb.delDish(dish);
				break;
			}
			case 6:
			{
				cout << "Enter dish to edit" << endl;
				getline(cin, dish);
				
				cout << "Enter new name of dish" << endl;
				getline(cin, newName);
				
				rb.edtDishName(dish, newName);
				break;
			}
			case 7:
			{
				cout << "Enter dish to edit" << endl;
				getline(cin, dish);
				
				cout << "Enter new ingredients one by one" << endl;
				cout << "Enter dish ingredient. Enter quit to stop" << endl;
				getline(cin, ingr);
				
				//ingrs.clear();
				while (ingr != "quit")
				{
					ingrs.push_back(ingr);
					cout << "Enter dish ingredient. Enter quit to stop" << endl;
					getline(cin, ingr);
				}
				
				rb.edtDishIngr(dish, ingrs);
				break;
			}
			case 8:
			{
				cout << "Enter dish to edit" << endl;
				getline(cin, dish);
				
				cout << "Enter new description" << endl;
				getline(cin, desc);
				
				rb.edtDishDesc(dish, desc);
				break;
			}
			case 9:
			{
				cout << "Enter dish to view" << endl;
				getline(cin, dish);
				rb.viewDishDetails(dish);
				break;
			}
			case 10:
			{
				rb.viewAllDishes();
				break;
			}
			case 11:
			{
				srch.cookable(ci, rb);
				break;
			}
			default:
			{
				cout << "Exiting" << endl;
				exit = true;
				break;
			}
		}
	}
	
	return 0;
}