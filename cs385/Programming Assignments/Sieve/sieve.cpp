/*******************************************************************************
 * Name        : sieve.cpp
 * Author      : Alexander Lu
 * Date        : 9/17/17
 * Description : Sieve of Eratosthenes
 * Pledge      : I pledge my Honor that I have abided by the Stevens Honor System
 ******************************************************************************/
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

class PrimesSieve {
public:
	/*
	 * Sieve constructor with an array of booleans and the limit for the number of primes you count to
	 */
    PrimesSieve(int limit) : is_prime_{new bool[limit + 1]}, limit_{limit} {
        sieve();
    }

    /*
     * deletes the array of booleans
     */
    ~PrimesSieve() {
        delete [] is_prime_;
    }

    /*
     * returns the number of prime numbers
     */
    inline int num_primes() const {
        return num_primes_;
    }


    /*
     * displays the prime numbers to a certain limit
     */
    void display_primes() const {


    cout<< "\nNumber of primes found: " << count_num_primes() << endl;
    cout<< "Primes up to " << limit_ << ":" << endl;

    const int max_prime_width = num_digits(max_prime_);
    int primes_per_row = 80 / (max_prime_width + 1);

    int count = 0;
    int spaces = 0;
    if(num_primes_>primes_per_row)
    {
    		for(int i=2; i<=limit_; i++)
    	    {
    	    		if(count==primes_per_row)
    	    		{
    	    			cout << endl;
    	    			count=0;
    	    		}
    			if(is_prime_[i]==true)
    			{
    				if(max_prime_==i)
    				{
    					cout <<i;

    				}
    				else
    				{
    					if(num_digits(i)<num_digits(max_prime_))
    					{
    						spaces = num_digits(max_prime_)-num_digits(i);
    						for(int z=0; z<spaces; z++)
    							cout << " ";
    					}
    					if(count == primes_per_row-1)
    					{
    						cout << i;
    						count++;
    					}
    					else
    					{
							cout << i << " ";
							count++;
    					}
    				}
    			}
    	    }
    }
    else{
    for(int i=2; i<=limit_; i++)
    {
		if(is_prime_[i]==true)
		{
			if(max_prime_==i)
			{
				cout <<i;

			}
			else
			{
				cout << i << " ";
			}
		}
    }
    }
    }

private:
    bool * const is_prime_;
    const int limit_;
    int num_primes_, max_prime_;

    /*
     * counts the number of prime numbers
     */
    int count_num_primes() const {
    	int count=0;
    		for(int i=2; i<=limit_; i++)
    		{
    			if(is_prime_[i]==true)
    			{
    				count+=1;
    			}
    		}
    		return count;
    }

    /*
     * counts the number of digits in a number
     */
    int num_digits(int num) const {
    		int temp=0;
        while(num!=0)
        {
        		temp++;
        		num = num/10;
        }
        return temp;
    }

    /*
     * makes the numbers that are prime true, and the numbers that aren't, false. Also updates the number of prime numbers
     * and the largest prime number
     */
    void sieve() {
    	for(int x=2; x<=limit_; x++)
    	{
    		is_prime_[x] =true;
    	}
    	for(int i=2; i<=sqrt(limit_); i++)
    	{
    		if (is_prime_[i] == true)
    		{

    			for(int j=i*i; j<=limit_; j = j + i)
    			{
    				is_prime_[j] = false;
    			}
    		}
    	}

    	for(int i=0; i<=limit_; i++)
    	{
    		if(is_prime_[i]==true)
    		{
    			max_prime_=i;
    			num_primes_ +=1;
    		}
    	}

    }
};

/*
 * Main function checks for errors, creates an object PrimeSieve and displays the prime numbers
 */
int main() {
    cout << "**************************** " <<  "Sieve of Eratosthenes" <<
            " ****************************" << endl;
    cout << "Search for primes up to: ";
    string limit_str;
    cin >> limit_str;
    int limit;


    // Use stringstream for conversion. Don't forget to #include <sstream>
    istringstream iss(limit_str);


    // Check for error.
    if ( !(iss >> limit) ) {
        cerr << "Error: Input is not an integer." << endl;
        return 1;
    }
    if (limit < 2) {
        cerr << "Error: Input must be an integer >= 2." << endl;
        return 1;
    }
    PrimesSieve ps(limit);
    ps.display_primes();

    return 0;
}
