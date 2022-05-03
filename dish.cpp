#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Ingredient
{
	public:
	Ingredient();
    
	void display(vector<string> v);
    void set_cur_names();
	void set_db_names();
	void set_db_index();
	
	void add_cur_names(string new_name);
	void add_db_names_index(string new_name);
	void del_cur_names(string del_name);
	void del_db_names_index(string del_name);
    
    vector<string> get_cur_names();
	vector<string> get_db_names();
	vector<int> get_db_index();
    
    private:
    vector<string> cur_names;
	vector<string> db_names;
	vector<int> db_index;
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
	cur_names.clear();
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
	db_names.clear();
	string name;
	ifstream infile("data2.txt");
	
	while (getline(infile, name))
	{
		db_names.push_back(name.substr(0, name.find_first_of(":")));
	}
	
	infile.close();
}

void Ingredient::set_db_index()
{
	db_index.clear();
	string index;
	ifstream infile("data2.txt");
	
	while (getline(infile, index))
	{
		int begin_pos = index.find(":",0) + 1; // index.find_first_of(":") + 1;
		db_index.push_back(stoi(index.substr(begin_pos)));
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

void Ingredient::add_cur_names(string new_name)
{
	for (int i = 0; i < cur_names.size(); i++)
	{
		if (cur_names[i] == new_name)
		{
			cout << "Ingredient already exists in the current ingredient list" << endl;
			return;
		}
	}
	
	ofstream outfile;
	outfile.open("data.txt", ofstream::app);
	outfile << new_name << endl;
	outfile.close();
	set_cur_names();
}

void Ingredient::add_db_names_index(string new_name)
{
	for (int i = 0; i < db_names.size(); i++)
	{
		if (db_names[i] == new_name)
		{
			cout << "Ingredient already exists in the ingredient database" << endl;
			return;
		}
	}
	
	ofstream outfile;
	outfile.open("data2.txt", ofstream::app);
	outfile << new_name << ":" << db_index.size() << endl;
	outfile.close();
	set_db_names();
	set_db_index();
}

void Ingredient::del_cur_names(string del_name)
{
	vector<string> temp = get_cur_names();
	
	int i;
	for (i = 0; i < temp.size(); i++)
	{
		if (temp[i] == del_name)
		{
			// delete item and return
			temp.erase(temp.begin()+1);
			break;
		}
	}
	
	if (i > temp.size())
	{
		cout << "Ingredient does not exist in the current ingredient list" << endl;
		return;
	}
	
	ofstream outfile;
	outfile.open("data.txt", ofstream::trunc);
	
	for (int j = 0; j < temp.size(); j++)
	{
		outfile << temp[j] << endl;
	}
	
	outfile.close();
	set_cur_names();
}

void Ingredient::del_db_names_index(string del_name) // call del_cur_names
{
	vector<string> temp = get_db_names();
	
	int i;
	for (i = 0; i < temp.size(); i++)
	{
		if (temp[i] == del_name)
		{
			// delete item and return
			temp.erase(temp.begin()+1);
			break;
		}
	}
	
	if (i > temp.size())
	{
		cout << "Ingredient does not exist in the ingredient database" << endl;
		return;
	}
	
	ofstream outfile;
	outfile.open("data2.txt", ofstream::trunc);
	
	for (int j = 0; j < temp.size(); j++)
	{
		outfile << temp[j] << ":" << j << endl;
	}
	
	outfile.close();
	set_db_names();
	set_db_index();
}

int main()
{
    Ingredient in = Ingredient();
    in.set_cur_names();
	in.set_db_names();
	in.set_db_index();

	bool exit = false;
	string choice;
	string ingr;
	
	while (exit == false)
	{
		cout << "Press 1 to view current available ingredients" << endl;
		cout << "Press 2 to add a new available ingredient" << endl;
		cout << "Press 3 to delete an ingredient" << endl;
		cout << "Press 4 to view ingredient database" << endl;
		cout << "Press 5 to add entry in ingredient database" << endl;
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
		}
	}
	
	return 0;
}