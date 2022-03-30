#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Ingredient
{
	public:
	Ingredient(vector<string> c_i_n, vector<string> d_i_n, vector<string> d_i_i); // constructor
	void current_ingr(vector<string> c_i_n); // display all current available ingredients
	void current_add(vector<string> &c_i_n, string a_ingr); // add ingredient to current available ingredients
	void current_del(vector<string> &c_i_n, string d_ingr); // delete ingredient from current available ingredients
	
	/*
	void all_ingr(string ingr); // display all ingredients in database
	void add_ingr(string ingr); // add ingredient to database
	void del_ingr(string ingr); // delete ingredient from database
	void update_ingr(string ingr); // update ingredients and their index in database
	*/
	private:
	vector<string> database_ingr_names; // parallel vector of all ingredients in database txt file
	vector<string> database_ingr_index; // parallel vector of all indexes of ingredients in database txt file
	vector<string> current_ingr_names; // vector of all ingredients in current available ingredient txt file
};

/*
class Dish
{
	public:
	
	private:
	
};
*/

Ingredient::Ingredient(vector<string> c_i_n, vector<string> d_i_n, vector<string> d_i_i)
{
	current_ingr_names = c_i_n;
	database_ingr_names = d_i_n;
	database_ingr_index = d_i_i;
}

void Ingredient::current_ingr(vector<string> c_i_n)
{
	if (c_i_n.size() != 0)
	{
		for (int i = 0; i < c_i_n.size(); i++)
		{
			cout << c_i_n[i] << endl;
		}
	}
	else
	{
		cout << "Empty" << endl;
	}
}

void Ingredient::current_add(vector<string> &c_i_n, string a_ingr)
{
	ofstream outfile;
	outfile.open("data.txt", ofstream::app);
	outfile << endl << a_ingr;
	c_i_n.push_back(a_ingr);
	outfile.close();
}

void Ingredient::current_del(vector<string> &c_i_n, string d_ingr)
{
	ifstream infile("data.txt");
	string name;
	vector<string> temp;
	
	while (infile >> name)
	{
		if(name != d_ingr)
		{
			temp.push_back(name);
		}
	}
	
	c_i_n.clear();
	for (int i = 0; i < temp.size(); i++)
	{
		c_i_n.push_back(temp[i]);
	}
	
	infile.close();
	
	ofstream outfile;
	outfile.open("data.txt", ofstream::trunc);
	
	for (int i = 0; i < c_i_n.size(); i++)
	{
		outfile << c_i_n[i] << endl;
	}
	
	outfile.close();
}

int main()
{
	//Ingredient list;
	vector<string> names;
	vector<string> b;
	vector<string> c;
	Ingredient list = Ingredient(names, b, c);
	string name;
	//list(names, b , c);
	ifstream infile("data.txt");
	
	while (infile >> name)
	{
		names.push_back(name);
	}
	
	bool exit = false;
	int choice;
	
	while (exit == false)
	{
		cout << "Press 1 to view current available ingredients" << endl;
		cout << "Press 2 to add a new available ingredient" << endl;
		cout << "Press 3 to delete an ingredient" << endl;
		cin >> choice;
		
		switch(choice)
		{
			case 1:
			{
				list.current_ingr(names);
				break;
			}
			case 2:
			{
			    cin.ignore();
			    string add;
			    getline(cin, add);
				list.current_add(names, add);
				break;
			}
			case 3:
			{
			    cin.ignore();
				string del;
				getline(cin, del);
				list.current_del(names, del);
				break;
			}
			default:
			{
				exit = true;
				break;
			}
		}
	}
	return 0;
	// write a menu with switch
	// 1. view current available ingredients
	// 2. add a current available ingredient
	// 3. delete a current available ingredient
	// 4. view ingredient database
	// 5. update ingredient database
	// 		1. delete entry in ingredient database
	// 		2. add entry in ingredient database
	// 6. view dish database
	// 7. update dish database
	//		1. add dish in dish database
	//		2. delete dish in dish database
	//		3. add ingredient(s) to dish in dish database
	//		4. delete ingredient(s) from dish in dish database
}