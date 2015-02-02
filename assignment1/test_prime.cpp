/* Author: Basil Vetas
 * Date: January 14, 2015
 * Course: CS 3505
 * Version: 1.0
 * 
 * A command-line application that determines if an integer is prime
 * The integer is passed in as a single command-line parameter
 * 
 * To compile:  g++ -o test_prime.o test_prime.cpp
 * To run:      ./test_prime.o n
 */
#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;

// Forward declarartion of prime check function
bool is_prime(int n);

int main(int argc, char* argv[])
{

  // if there are the wrong number of arguments, return error message
  if(argc < 2)
    {
      cout << "You have entered too few parameters. Please enter exactly one integer as a parameter." << endl;
      return 1;
    }
  else if(argc > 2)
    {
      cout << "You have entered too many parameters. Please enter exactly one integer as a parameter." << endl;
      return 1;
    }
  else
    {
      // pass argument to a string stream
      istringstream in(argv[1]);
      int value;

      // if we can pass the string stream to an int
      // and it is the end of the string stream
      // then it is a valid integer to evaluate if prime
      if((in >> value) && in.eof())
      {
        if(is_prime(value))
          cout << "prime" << endl;      
        else
          cout << "composite" << endl; 
      }
      else
        cout << "composite" << endl;
    }

  return 0;
}

/* Determines if the integer parameter is a prime number 
 * 
 * Parameters:
 *   int n - the integer to be checked
 *
 * Return value:
 *   true if the integer is prime, false otherwise
 */
bool is_prime (int n)
{
  // 0, 1, and negatives are not prime
  if(n <= 1)
    return false;

  // base case, 2 is prime
  if(n == 2)
    return true;

  // if n/2 has no remainder then it is even, and thus composite
  if((n % 2) == 0)
    return false;

  // otherwise, n is odd, so we need to check if n is dividible
  // by any prime factor between 3 and square root of n

  // get square root, round up with ceiling function
  int root = (int) ceil(sqrt(n)); 

  for(int i = 3; i <= root; i++)
    {
      // recursive optimization, only divide by prime factors
      if(is_prime(i))
  {
    // if any n/i has remainder of 0, then it is composite
    if((n % i) == 0)
    return false;
  }    
    }
  
  // otherwise n must be prime
  return true;
}


