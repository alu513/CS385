/*******************************************************************************
 * Name        : unique.cpp
 * Author      : Alexander Lu
 * Date        : 9/24/17
 * Description : Determining uniqueness of chars with int as bit vector.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System
 ******************************************************************************/
#include <iostream>
#include <cctype>

using namespace std;

bool is_all_lowercase(const string &s) {
    // TODO: returns true if all characters in string are lowercase
    // letters in the English alphabet; false otherwise.

	for(unsigned int i=0; i<s.length();i++){
			if(!(isalpha(s[i])))
			{
				return false;
			}
			if(isupper(s[i]))
			{
				return false;
			}

		}
	return true;
}

bool all_unique_letters(const string &s) {
    // TODO: returns true if all letters in string are unique, that is
    // no duplicates are found; false otherwise.
    // You may use only a single int for storage and work with bitwise
    // and bitshifting operators.
    // No credit will be given for other solutions.

	unsigned int setnum = 0;
	for(unsigned int i=0; i<s.length();i++){
		if((setnum & (1<<(s[i]-97))) > 0)
			return false;
		else
			setnum = setnum | (1<<(s[i]-97));
	}
	return true;
}

int main(int argc, char * const argv[]) {
    // TODO: reads and parses command line arguments.
    // Calls other functions to produce correct output.


		if (argc==1){
				cerr << "Usage: ./unique <string>" << endl;
				return 1;
			}

		if (argc > 2){
				cerr << "Usage: ./unique <string>" << endl;
				return 1;
		}


		if(is_all_lowercase(argv[1])==false){
			cerr << "Error: String must contain only lowercase letters.";
			return 1;
		}

		if(all_unique_letters(argv[1])==false){
			cerr << "Duplicate letters found.";
			return 1;
		}

		if(all_unique_letters(argv[1])==true)
		{
			cout << "All letters are unique.";
		}

		return 0;

}
