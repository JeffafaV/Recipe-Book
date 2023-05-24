#include <iostream>
#include <string>
#include <vector>
#include "shell.h"

using namespace std;

Shell::Shell()
{
	
}

void Shell::addingCIngr()
{
	string ingr;
	cout << "Enter ingredient to add" << endl;
	getline(cin, ingr);
	
	if (ingr.empty() == true)
	{
		cout << "Input can't be empty" << endl;
		return;
	}
	
	ci.addCIngr(ingr);
}

void Shell::deletingCIngr()
{
	string ingr;
	cout << "Enter ingredient to delete" << endl;
	getline(cin, ingr);
	
	if (ingr.empty() == true)
	{
		cout << "Input can't be empty" << endl;
		return;
	}
	
	ci.delCIngr(ingr);
}

void Shell::viewingCIngr()
{
	cout << "List of currently available ingredients:" << endl;
	ci.viewCIngr();
}

void Shell::addingDish()
{
	string dish;
	cout << "Enter dish to add" << endl;
	getline(cin, dish);
	
	string ingr;
	cout << "Enter new ingredients one by one" << endl;
	cout << "Enter dish ingredient. Enter quit to stop" << endl;
	getline(cin, ingr);
	
	vector<string> ingrs;
	while (ingr != "quit") /*can probably do do while loop*/
	{
		ingrs.push_back(ingr);
		cout << "Enter dish ingredient. Enter quit to stop" << endl;
		getline(cin, ingr);
	}
	
	string desc;
	cout << "Enter dish description/recipe" << endl;
	getline(cin, desc);
	
	if (dish.empty() == true || ingrs.empty() == true || desc.empty() == true)
	{
		cout << "Any input can't be empty" << endl;
		return;
	}
	
	rb.addDish(dish, ingrs, desc);
}

void Shell::editingDishName()
{
	string dish;
	cout << "Enter dish to edit" << endl;
	getline(cin, dish);
	
	string newName;
	cout << "Enter new name of dish" << endl;
	getline(cin, newName);
	
	if(dish.empty() == true || newName.empty() == true)
	{
		cout << "Any input can't be empty" << endl;
		return;
	}
	
	rb.edtDishName(dish, newName);
}

void Shell::editingDishIngr()
{
	string dish;
	cout << "Enter dish to edit" << endl;
	getline(cin, dish);
	
	string ingr;
	cout << "Enter new ingredients one by one" << endl;
	cout << "Enter dish ingredient. Enter quit to stop" << endl;
	getline(cin, ingr);
	
	vector<string> ingrs;
	while (ingr != "quit") /*can probably do do while loop*/
	{
		ingrs.push_back(ingr);
		cout << "Enter dish ingredient. Enter quit to stop" << endl;
		getline(cin, ingr);
	}
	
	if (dish.empty() == true || ingrs.empty() == true)
	{
		cout << "Any input can't be empty" << endl;
		return;
	}
	
	rb.edtDishIngr(dish, ingrs);
}

void Shell::editingDishDesc()
{
	string dish;
	cout << "Enter dish to edit" << endl;
	getline(cin, dish);
	
	string desc;
	cout << "Enter new description" << endl;
	getline(cin, desc);
	
	if (dish.empty() == true || desc.empty() == true)
	{
		cout << "Any input can't be empty" << endl;
		return;
	}
	
	rb.edtDishDesc(dish, desc);
}

void Shell::deletingDish()
{
	string dish;
	cout << "Enter dish to delete" << endl;
	getline(cin, dish);
	
	if (dish.empty() == true)
	{
		cout << "Input can't be empty" << endl;
		return;
	}
	
	rb.delDish(dish);
}

void Shell::viewingDishDetails()
{
	string dish;
	cout << "Enter dish to view" << endl;
	getline(cin, dish);
	
	if (dish.empty() == true)
	{
		cout << "Input can't be empty" << endl;
		return;
	}
	
	rb.viewDishDetails(dish);
}

void Shell::viewingAllDishes()
{
	cout << "List of dishes stored in the recipe book:" << endl;
	rb.viewAllDishes();
}

void Shell::cookableDishes()
{
	cout << "Cookable dishes:" << endl;
	srch.cookable(ci, rb);
}