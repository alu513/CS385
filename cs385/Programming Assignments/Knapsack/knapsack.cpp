//============================================================================
// Name        : knapsack.cpp
// Author      : Alexander Lu
// Pledge      : I pledge my honor that I have abided by the Stevens Honor System
//============================================================================
#include <sstream>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cctype>

using namespace std;

struct Item {
 unsigned int item_number, weight, value;
 string description;
 explicit Item(const unsigned int item_number, const unsigned int weight, const unsigned int value, const string &description) :
 item_number(item_number), weight(weight), value(value), description(description) { }

 friend std::ostream& operator<<(std::ostream& os, const Item &item) {
 os << "Item " << item.item_number << ": " << item.description << " (" << item.weight
 << (item.weight == 1 ? " pound" : " pounds") << ", $" << item.value << ")";
 os.flush();
 return os;
 }
};

vector<string> remove(const string &input, char between){
	istringstream iss(input);
	string s;
	vector<string> values;
	while(getline(iss, s, between)){
		values.push_back(s);
	}
	return values;
}

int max(int a,int b)
{
	if(a>b)
	{
		return a;
	}
	return b;
}

void answer(vector<Item> list, unsigned int cap)
{
	int **array = new int*[list.size()];

		for(unsigned int i=0; i<=list.size(); i++)
		{
			array[i] = new int[cap+1];
			for(unsigned int j=0; j<=cap; j++)
			{
				if(i==0 || j==0)
				{
					array[i][j]=0;
				}
				else if(list[i-1].weight<=j)
				{
					array[i][j] = max(list[i-1].value + array[i-1][j-list[i-1].weight],array[i-1][j]);
				}
				else
				{
					array[i][j] = array[i-1][j];
				}
			}
		}

		vector<Item> reverse, inorder;
		int l = list.size();
		int c = cap;

		while(l>0 && c>0)
		{
			if(array[l][c] > array[l-1][c])
			{
				reverse.push_back(list[l-1]);
				c = c-list[l-1].weight;
			}
			l--;
		}
		for(int z=reverse.size()-1; z>=0; z--)
		{
			inorder.push_back(reverse[z]);
		}

		if(inorder.size()==0)
		{
				cout << "Items to place in knapsack:";
				cout << " None" << endl;
		}
		else{
				cout << "Items to place in knapsack:" << endl;
				for(unsigned int x=0; x<inorder.size(); x++)
				{
					cout << "   " << inorder[x] << endl;
				}
		}
					int finalweight = 0;
					int finalvalue = 0;

					for(unsigned int i=0; i<inorder.size(); i++)
					{
						finalweight += inorder[i].weight;
						finalvalue += inorder[i].value;
					}

					if(finalweight==1)
					{
						cout << "Total weight: " << finalweight << " pound" << endl;
					}
					else
					{
						cout << "Total weight: " << finalweight << " pounds" << endl;
					}
					cout << "Total value : $" << finalvalue << endl;
}



int main(int argc, char * const argv[]) {
	if(argc != 3){
			cerr << "Usage: " << argv[0] << " <capacity> <filename>" << endl;
			return 1;
	}

	int cap;
		istringstream iss(argv[1]);
		if ( (!(iss >> cap)) || (cap < 0) ) {
				cerr << "Error: Bad value '" << argv[1] << "' for capacity." << endl;
			return 1;
		}

	ifstream file(argv[2]);
	if(!file){
			cerr << "Error: Cannot open file '" << argv[2] << "'." << endl;
			return 1;
	}

	vector<Item> list;
	string desc, weight, value, line;
	int weight_num=0;
	int value_num=0;
	int line_num = 1;

	while (getline(file, line)) {
		vector<string> values;
		values = remove(line,',');

		if(values.size()!=3)
		{
			cerr << "Error: Line number " << line_num << " does not contain 3 fields." << endl;
			return 1;
		}

		desc = values[0];
		weight = values[1];
		value = values[2];

		istringstream iss2(weight);
		if(!(iss2 >> weight_num) || weight_num<0){
			cerr << "Error: Invalid weight '" << values[1] << "' on line number " << line_num << "." << endl;
			return 1;
		}

		istringstream iss3(value);
		if(!(iss3 >> value_num) || value_num<0){
			cerr << "Error: Invalid value '" << values[2] << "' on line number " << line_num << "." << endl;
			return 1;
		}

		Item item = Item(line_num, weight_num, value_num, desc);
		list.push_back(item);
		line_num++;

	}


	cout << "Candidate items to place in knapsack:" << endl;

	for(unsigned int x=0; x<list.size(); x++)
	{
		cout << "   " << list[x] << endl;
	}

	if(cap==1)
	{
		cout << "Capacity: " << cap << " pound" << endl;
	}
	else{
		cout << "Capacity: " << cap << " pounds" << endl;
	}

	answer(list,cap);
	return 0;
}
