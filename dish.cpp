#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Ingredient
{
	public:
	Ingredient(vector<string> c_i_n, vector<string> d_i_n, vector<int> d_i_i); // constructor
	void current_ingr(vector<string> c_i_n); // display all current available ingredients
	void current_add(vector<string> &c_i_n, vector<string> &d_i_n, vector<int> &d_i_i, string a_ingr); // add ingredient to current available ingredients
	void current_del(vector<string> &c_i_n, string d_ingr); // delete ingredient from current available ingredients
	
	void all_ingr(vector<string> &d_i_n); // display all ingredients in database
	void add_ingr(vector<string> &d_i_n, vector<int> &d_i_i, string a_ingr); // add ingredient to database
	//void del_ingr(string ingr); // delete ingredient from database
	//void update_ingr(string ingr); // update ingredients and their index in database
	
	private:
	vector<string> database_ingr_names; // parallel vector of all ingredients in database txt file
	vector<int> database_ingr_index; // parallel vector of all indexes of ingredients in database txt file
	vector<string> current_ingr_names; // vector of all ingredients in current available ingredient txt file
};

/*
class Dish
{
	public:
	
	private:
	
};
*/
// not sure if I should even be doing classes
Ingredient::Ingredient(vector<string> c_i_n, vector<string> d_i_n, vector<int> d_i_i)
{
	current_ingr_names = c_i_n;
	database_ingr_names = d_i_n;
	database_ingr_index = d_i_i;
}

// all current ingredients were stored in a vector in main function
// this function displays each current available ingredient
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

// adds an ingredient to the currently available ingredient vector and text file
// the ingredient is appended in the text file and pushed back in the vector
// if added ingredient is not in the database then it is added
void Ingredient::current_add(vector<string> &c_i_n, vector<string> &d_i_n, vector<int> &d_i_i, string a_ingr)
{
	for (int i = 0; i < c_i_n.size(); i++)
    {
        if (c_i_n[i] == a_ingr)
        {
            cout << "Ingredient already exists" << endl;
            return;
        }
    }
	
	ofstream outfile;
	outfile.open("data.txt", ofstream::app);
	outfile << a_ingr << endl;
	c_i_n.push_back(a_ingr);
	outfile.close();
	
	// checks if added ingredient is in ingredient data base
	for (int i = 0; i < d_i_n.size(); i++)
	{
		if (d_i_n[i] == a_ingr) // returns if a_ingr is found in data base
		{
			return;
		}
	}
	
	// adds a_ingr to database
	add_ingr(d_i_n, d_i_i, a_ingr);
}

// deletes an ingredient from the currently available ingredient vector and text file
// the available ingredients are first stored in a temporary vector except for the ingredient that is being deleted
// the original vector is cleared of its elements and then copies the temporary vector's elements
// the available ingredient text file is truncated and is filled with the original vector's elements
// I think I can do this with just one fstream instead of using both ifstream and ofstream
void Ingredient::current_del(vector<string> &c_i_n, string d_ingr)
{
	int i;
	
	for (i = 0; i < c_i_n.size(); i++)
	{
		if (c_i_n[i] == d_ingr)
		{
			cout << "Element found at index " << i << endl;
			c_i_n.erase(c_i_n.begin()+i);
			break;
		}
	}
	cout << i << " " << c_i_n.size() << endl;
	if (i > c_i_n.size())
	{
		cout << "Ingredient does not exist" << endl;
		return;
	}
	
	ofstream outfile;
	outfile.open("data.txt", ofstream::trunc);
	
	for (int j = 0; j < c_i_n.size(); j++)
	{
		outfile << c_i_n[j] << endl;
	}
	
	outfile.close();
}

void Ingredient::all_ingr(vector<string> &d_i_n)
{
	/*
	ifstream infile("data2.txt");
	string temp;
	
	while (getline(infile, temp))
	{
		d_i_n.push_back(temp.substr(0, temp.find_first_of(":")));
	}
	*/
	for (int i = 0; i < d_i_n.size(); i++)
	{
		cout << d_i_n[i] << endl;
	}
}

void Ingredient::add_ingr(vector<string> &d_i_n, vector<int> &d_i_i, string a_ingr)
{
	for (int i = 0; i < d_i_n.size(); i++)
    {
        if (d_i_n[i] == a_ingr)
        {
            cout << "Ingredient already exists" << endl;
            return;
        }
    }
	
	ofstream outfile;
	outfile.open("data2.txt", ofstream::app);
	//cout << d_i_i.size();
	/*
	if(d_i_i.empty() == true)
	{
		outfile << a_ingr << ":" << 0 << endl;
		d_i_n.push_back(a_ingr);
		d_i_i.push_back(0);
	}
	*/
	else
	{
		outfile << a_ingr << ":" << d_i_i.size() << endl;
		d_i_n.push_back(a_ingr);
		d_i_i.push_back(d_i_i.size());
	}
	
	outfile.close();
}

int main()
{
	//Ingredient list;
	vector<string> names; // test
	vector<string> base_names; // test
	vector<int> c; // dummy
	Ingredient list = Ingredient(names, base_names, c);
	string name;
	//list(names, b , c);
	ifstream infile("data.txt");
	
	// maybe change to getline
	while (getline(infile, name))
	{
		names.push_back(name);
	}
	
	ifstream infile_2("data2.txt");
	string base_name;
	
	while (getline(infile_2, base_name))
	{
		base_names.push_back(base_name.substr(0, base_name.find_first_of(":")));
	}
	
	bool exit = false;
	int choice;
	
	while (exit == false)
	{
		cout << "Press 1 to view current available ingredients" << endl;
		cout << "Press 2 to add a new available ingredient" << endl;
		cout << "Press 3 to delete an ingredient" << endl;
		cout << "Press 4 to view ingredient database" << endl;
		cout << "Press 5 to add entry in ingredient database" << endl;
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
			    cin.ignore(); // have to clear the buffer first or else getline will not take input
			    string add;
			    getline(cin, add);
				list.current_add(names, base_names, c, add);
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
			case 4:
			{
				list.all_ingr(base_names);
				break;
			}
			case 5:
			{
				cin.ignore();
				string add_to_d;
				getline(cin, add_to_d);
				list.add_ingr(base_names,c,add_to_d);
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