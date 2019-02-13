/*
 * rpmult.cpp
 *
 *  Created on: Oct 22, 2017
 *      Author: alexanderlu
 *      I pledge my Honor that I have abided by the Stevens Honor System
 */

#include <iostream>
#include <sstream>
using namespace std;


/*
 * function that does the rpm with bitshifting
 */
   unsigned long russian_peasant_multiplication(unsigned int m, unsigned int n){
	   unsigned long temp =0;
	   unsigned long m1 = m;
	   unsigned long n1 = n;


	   while(n1>0)
	   {
		   if(n1%2!=0)
		   {
			   temp += m1;

		   }
		   m1 = m1 << 1;
		   n1 = n1 >> 1;
	   }
	   return temp;
   }

   /*
    * Checks if the arguments are numbers
    */
   bool is_number(const string &s) {

   	for(unsigned long i=0; i<s.length();i++){
   			if(!(isdigit(s[i])))
   			{
   				return false;
   			}
   		}
   	return true;
   }



   /*
    * main function that checks for errors
    */
  int main(int argc, char *argv[]) {

       if (argc != 3) {
    	   	   cerr << "Usage: " << argv[0] << " <integer m> <integer n>" <<endl;
           return 1;
       }

       if (!is_number(argv[1]))
       {
    	   	   cerr << "Error: The first argument is not a valid nonnegative integer." << endl;
    	   	   return 1;
       }

       if (!is_number(argv[2]))
       {
           cerr << "Error: The second argument is not a valid nonnegative integer." << endl;
           return 1;
       }

       unsigned int temp1 = 0;
       unsigned int temp2 = 0;
       istringstream iss;

       iss.str(argv[1]);
       iss >> temp1;
       iss.clear();
       iss.str(argv[2]);
       iss >> temp2;
       iss.clear();

       if(temp1 > 2147483647)
       {
            cerr << "Error: The first argument is not a valid nonnegative integer." << endl;
            return 1;
       }
       if(temp2 > 2147483647)
       {
    	   	   cerr << "Error: The second argument is not a valid nonnegative integer." << endl;
    	       return 1;
       }

       if(temp2>temp1)
       {
           int t;
           t = temp1;
           temp1 = temp2;
           temp2 = t;
           cout << temp2 << " x " << temp1 << " = " << russian_peasant_multiplication(temp1,temp2);
           return 1;
        }

       cout << temp1 << " x " << temp2 << " = " << russian_peasant_multiplication(temp1,temp2);


   }
