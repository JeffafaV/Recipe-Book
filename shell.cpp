#include <iostream>
#include <string>
#include <vector>

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
	ci.viewCIngr();
}

void Shell::addingDish()
{
	string dish;
	cout << "Enter dish to add" << endl;
	getline(cin, dish);
	
	string ingr;
	cout << "Enter dish ingredient. Enter quit to stop" << endl;
	getline(cin, ingr);
	
	vector<string> ingrs;
	while (ingr != "quit")
	{
		ingrs.push_back(ingr);
		cout << "Enter dish ingredient. Enter quit to stop" << endl;
		getline(cin, ingr);
	}
	
	cout << "Enter dish description/recipe" << endl;
	getline(cin, desc);
	
	if (dish.empty() == true || ingrs.empty() == true || desc.empty() == true)
	{
		cout << "Input can't be empty" << endl;
		return;
	}
	
	rb.addDish(dish, ingrs, desc);
}

void Shell::editingDishName()
{
	
}

void Shell::editingDishIngr()
{
	
}

void Shell::editingDishDesc()
{
	
}

void Shell::deletingDish()
{
	
}

void Shell::viewingDishDetails()
{
	
}

void Shell::viewingAllDishes()
{
	
}

void Shell::cookableDishes()
{
	
}