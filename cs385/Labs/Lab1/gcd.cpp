/*
 * gcd.cpp
 * I pledge my honor that I have abided by the Stevens Honor System
 *  Created on: Sep 1, 2017
 *      Author: alexanderlu
 */

#include <iostream>
#include <sstream>

using namespace std;

int recurse(int t, int y)
/* This function returns the gcd recursively*/
{
	if (t<0)
	{
		t = abs(t);
	}
	if (y<0)
	{
		y = abs(y);
	}
	if (y== 0) {
	      return t;
	    }
	else
	{
	      return recurse(y, t%y);

	}

}

int iterative(int a, int b)
/* This function returns the gcd iteratively*/
{
	if (a<0)
	{
		a = abs(a);
	}
	if (b<0)
	{
		b = abs(b);
	}
    if (a==0 && b==0)
    {
    		return 0;
    }

    if (a==0 || b==0)
    {
    		return max(a,b);
    }


	int temp = 1;
	for(int i=1; i<=min(a,b); i++)
	{
		if(a%i==0 && b%i==0)
		{
			temp = i;
		}
	}
	return temp;
}



int main(int argc, char* const argv[])
/*Main function that checks for errors and prints the results of the functions*/
{
	int a,b;
	istringstream iss;
	if (argc !=3){
			cerr <<"Usage: " << argv[0] << " <integer m> <integer n>" << endl;
			return 1;
		}

	iss.str(argv[1]);

	if(!(iss>>a)){
		cerr << "Error: The first argument is not a valid integer.";
		return 1;
	}

	iss.clear();

	iss.str(argv[2]);
	if (!(iss>>b))
	{
		cerr<< "Error: The second argument is not a valid integer." << endl;
		return 1;
	}

	int it = iterative(a,b);
	cout << "Iterative: gcd(" << a << ", " << b << ") = " << it << endl;

	int re = recurse(a,b);
	cout << "Recursive: gcd(" << a << ", " << b << ") = " << re << endl;


}


