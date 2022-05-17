#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Ingredient
{
	public:
	Ingredient();
    
	void display(vector<string> v); // displays vector
    void set_cur_names(); // sets the cur_names vector to the names in the current ingredient file
	void set_db_names(); // sets the db_names vector to the names in the ingredient database file
	void set_db_index(); // sets the db_index vector to the indeces of the names in the ingredient database file
	
	void add_cur_names(string new_name); // adds a new current ingredient in the current ingredient file
	void add_db_names_index(string new_name); // adds a new ingredient and its index in the ingredient database file
	void del_cur_names(string del_name); // deletes a current ingredient in the current ingredient file
	void del_db_names_index(string del_name); // deletes an ingredient and its index in the ingredient database file
    
    vector<string> get_cur_names(); // returns cur_names
	vector<string> get_db_names(); // returns db_names
	vector<int> get_db_index(); // return db_index
    
    private:
    vector<string> cur_names; // vector for ingredient names in the current ingredient file
	vector<string> db_names; // vector for ingredient names in the ingredient database
	vector<int> db_index; // vector for ingredient indeces in the ingredient database
};

Ingredient::Ingredient()
{
    vector<string> cur_names = {};
	vector<string> db_names = {};
	vector<int> db_index = {};
}

void Ingredient::display(vector<string> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
}

void Ingredient::set_cur_names()
{
	cur_names.clear(); // have to clear the vector first and then push values
    string name;
    ifstream infile("data.txt");
    
    while (getline(infile, name))
    {
		cur_names.push_back(name);
    }
    
	infile.close();
}

void Ingredient::set_db_names()
{
	db_names.clear(); // have to clear the vector first and then push values
	string name;
	ifstream infile("data2.txt");
	
	while (getline(infile, name))
	{
		db_names.push_back(name.substr(0, name.find_first_of(":"))); // push only the name
	}
	
	infile.close();
}

void Ingredient::set_db_index()
{
	db_index.clear(); // have to clear the vector first and then push values
	string index;
	ifstream infile("data2.txt");
	
	while (getline(infile, index))
	{
		int begin_pos = index.find(":",0) + 1; // index.find_first_of(":") + 1;
		db_index.push_back(stoi(index.substr(begin_pos))); // push only the index
	}
	
	infile.close();
}

vector<string> Ingredient::get_cur_names()
{
    return cur_names;
}

vector<string> Ingredient::get_db_names()
{
	return db_names;
}

vector<int> Ingredient::get_db_index()
{
	return db_index;
}

void Ingredient::add_cur_names(string new_name) // should call add_db_names_index
{
	// checks if ingredient already exists
	for (int i = 0; i < cur_names.size(); i++)
	{
		if (cur_names[i] == new_name)
		{
			cout << "Ingredient already exists in the current ingredient list" << endl;
			return;
		}
	}
	
	// adds ingredient to the current ingredient list and then sets its corresponding vector
	ofstream outfile;
	outfile.open("data.txt", ofstream::app);
	outfile << new_name << endl;
	outfile.close();
	set_cur_names();
}

void Ingredient::add_db_names_index(string new_name)
{
	// checks if ingredient already exists
	for (int i = 0; i < db_names.size(); i++)
	{
		if (db_names[i] == new_name)
		{
			cout << "Ingredient already exists in the ingredient database" << endl;
			return;
		}
	}
	
	vector<string> temp_n = get_db_names();
	vector<int> temp_i = get_db_index();
	
	// adds ingredient to the ingredient database and then sets its corresponding vectors
	ofstream outfile;
	outfile.open("data2.txt", ofstream::trunc);
	
	bool was_cont = true; // true if [1...n]
	
	int j;
	for (j = 0; j < temp_i.size()-1; j++)
	{
		if (j+1 != temp_i[j])
		{
			was_cont = false;
			break;
			
		}
	}
	
	if (was_cont == true)
	{
		temp_n.push_back(new_name);
		temp_i.push_back(temp_i.size()+1);
	}
	else
	{
		temp_n.insert(temp_n.begin()+j, new_name);
		temp_i.insert(temp_i.begin()+j, j+1);
	}
	
	for (int k = 0; k < db_names.size(); k++)
	{
		outfile << db_names[k] << ":" << db_index[k] << endl;
	}
	
	outfile.close();
	set_db_names();
	set_db_index();
}

void Ingredient::del_cur_names(string del_name)
{
	// create a temporary vector to modify
	vector<string> temp = get_cur_names();
	
	//int i;
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i] == del_name)
		{
			// delete item and return
			temp.erase(temp.begin() + i);
			break;
		}
	}
	
	// checks if ingredient doesn't exist
	if (temp == cur_names) // i > temp.size()
	{
		cout << "Ingredient does not exist in the current ingredient list" << endl;
		return;
	}
	
	// rewrites the current ingredient list with the temporary vector which doesn't include the deleted ingredient and then sets its corresponding vector
	ofstream outfile;
	outfile.open("data.txt", ofstream::trunc);
	
	for (int j = 0; j < temp.size(); j++)
	{
		outfile << temp[j] << endl;
	}
	
	outfile.close();
	set_cur_names();
}

void Ingredient::del_db_names_index(string del_name)
{
	// create temporary vectors to modify
	vector<string> temp_n = get_db_names();
	vector<int> temp_i = get_db_index();
	
	//int i;
	for (int i = 0; i < temp_n.size(); i++)
	{
		if (temp_n[i] == del_name)
		{
			// delete item and return
			temp_n.erase(temp_n.begin() + i);
			temp_i.erase(temp_i.begin() + i);
			break;
		}
	}
	
	// checks if ingredient doesn't exist
	if (temp_n == db_names) // i > temp.size()
	{
		cout << "Ingredient does not exist in the ingredient database" << endl;
		return;
	}
	
	// rewrites the ingredient database with the temporary vectors which doesn't include the deleted ingredient and then sets its corresponding vectors
	ofstream outfile;
	outfile.open("data2.txt", ofstream::trunc);
	
	for (int j = 0; j < temp_n.size(); j++)
	{
		outfile << temp_n[j] << ":" << temp_i[j] << endl;
	}
	
	outfile.close();
	set_db_names();
	set_db_index();
	del_cur_names(del_name);
}

////////////////////////////////////////////////////////////////////////////////////////////////
class Dish
{
	public:
	Dish();
	
	void set_dish_names();
	
	vector<string> get_dish_names();
	
	private:
	vector<string> dish_names;
};

Dish::Dish()
{
	dish_names = {};
}

void Dish::set_dish_names()
{
	dish_names.clear();
    string name;
    ifstream infile("data3.txt");
    
    while (getline(infile, name))
    {
		dish_names.push_back(name);
    }
    
	infile.close();
}

vector<string> Dish::get_dish_names()
{
	return dish_names;
}

int main()
{
    Ingredient in = Ingredient();
    in.set_cur_names();
	in.set_db_names();
	in.set_db_index();
	
	Dish di = Dish();
	di.set_dish_names();

	bool exit = false;
	string choice;
	string ingr;
	
	while (exit == false)
	{
		cout << "Press 1 to view currently available ingredients" << endl;
		cout << "Press 2 to add a new ingredient to the currently available ingredient list" << endl;
		cout << "Press 3 to delete an ingredient from the currently available ingredient list" << endl;
		cout << "Press 4 to view ingredient database" << endl;
		cout << "Press 5 to add an ingredient to the ingredient database" << endl;
		cout << "Press 6 to delete an ingredient from the ingredient database" << endl;
		cout << "Press 7 to view dish database" << endl;
		getline(cin, choice);
		
		switch (stoi(choice))
		{
			case 1:
			{
				in.display(in.get_cur_names());
				break;
			}
			case 2:
			{
				cout << "Enter the ingredient you want to add to the current ingredient list:" << endl;
				getline(cin, ingr);
				in.add_cur_names(ingr);
				break;
			}
			case 3:
			{
				cout << "Enter the ingredient you want to delete from the current ingredient list:" << endl;
				getline(cin, ingr);
				in.del_cur_names(ingr);
				break;
			}
			case 4:
			{
				in.display(in.get_db_names());
				break;
			}
			case 5:
			{
				cout << "Enter the ingredient you want to add to the ingredient database:" << endl;
				getline(cin, ingr);
				in.add_db_names_index(ingr);
				break;
			}
			case 6:
			{
				cout << "Enter the ingredient you want to delete from the ingredient database:" << endl;
				getline(cin, ingr);
				in.del_db_names_index(ingr);
				break;
			}
			case 7:
			{
				vector<string> list = di.get_dish_names();
				for (int i = 0; i < list.size(); i++)
				{
					cout << list[i] << endl;
				}
				break;
			}
		}
	}
	
	return 0;
}