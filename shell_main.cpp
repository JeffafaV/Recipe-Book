#include <iostream>
#include <string>
#include <vector>
#include "shell.h"

using namespace std;

int main()
{
	Shell sh;
	
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
		int menuChoice;
		cin >> menuChoice;
		cin.ignore();
		
		switch (menuChoice)
		{
			case 1:
			{
				sh.addingCIngr();
				break;
			}
			case 2:
			{
				sh.deletingCIngr();
				break;
			}
			case 3:
			{
				sh.viewingCIngr();
				break;
			}
			case 4:
			{
				sh.addingDish();
				break;
			}
			case 5:
			{
				sh.deletingDish();
				break;
			}
			case 6:
			{
				sh.editingDishName();
				break;
			}
			case 7:
			{
				sh.editingDishIngr();
				break;
			}
			case 8:
			{
				sh.editingDishDesc();
				break;
			}
			case 9:
			{
				sh.viewingDishDetails();
				break;
			}
			case 10:
			{
				sh.viewingAllDishes();
				break;
			}
			case 11:
			{
				sh.cookableDishes();
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