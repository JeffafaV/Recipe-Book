#include <iostream>
#include <string>
#include <vector>
#include "shell.h"

using namespace std;

int main()
{
	Search srch;
	
	bool exit = false;
	
	while (exit == false)
	{
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
				srch.addingCIngr();
				break;
			}
			case 2:
			{
				srch.deletingCIngr();
				break;
			}
			case 3:
			{
				srch.viewingCIngr();
				break;
			}
			case 4:
			{
				srch.addingDish();
				break;
			}
			case 5:
			{
				srch.deletingDish();
				break;
			}
			case 6:
			{
				srch.editingDishName();
				break;
			}
			case 7:
			{
				srch.editingDishIngr();
				break;
			}
			case 8:
			{
				srch.editingDishDesc();
				break;
			}
			case 9:
			{
				srch.viewingDishDetails();
				break;
			}
			case 10:
			{
				srch.viewingAllDishes();
				break;
			}
			case 11:
			{
				srch.cookableDishes();
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