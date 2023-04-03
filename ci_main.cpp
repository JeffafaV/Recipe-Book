#include <iostream>
#include <string>
#include "current_ingredients.h"

using namespace std;

int main()
{
	CurrentIngredients ci;
	
	bool exit = false;
	int menuChoice;
	string ingr;
	while (exit == false)
	{
		cout << "1 to add" << endl;
		cout << "2 to delete" << endl;
		cout << "3 to view" << endl;
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