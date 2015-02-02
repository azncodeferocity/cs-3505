/* Author: Basil Vetas
 * Date: January 14, 2015
 * Course: CS 3505
 * Version: 1.0
 *
 * A command line application that converts kilograms to pounds for the user.
 *
 * To compile:  g++ -o convert_mass.o convert_mass.cpp
 * To run:      ./convert_mass.o 
 */
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
using namespace std;

// Forward declarartion of conversion function
double convert_mass (double kilos);

int main()
{
  double kg, lbs;
  string input;
  // prompt user to enter a weight in kilograms
  cout << "Please enter a weight in Kilograms: ";
  // receive the line entered from user 
  getline(cin, input);  

  // check that the input is not null (and thus is a valid number)
  if(cin.fail() == true)
    {    
      cout << "The value you have entered is invalid. Please enter a valid weight in kg and try again." << endl;
      return 1; 
    }

  // pass it to a stringstream
  istringstream in(input);
  
  // get the integer from stream
  // and make sure it is the end of line
  if((in >> kg) && in.eof())
    {
      lbs = convert_mass(kg);
      // output the result for the user                                                                                       
      cout << "You entered " << kg << setprecision(2) << fixed << " kg, which is equal to " << lbs << " lbs." << endl;    
    }
  else  // if we couldn't pass stream to int, or it wasn't the end of the line then it is invalid
    {
      cout << "The value you have entered is invalid. Please enter a valid weight in kg and try again." << endl;
      return 1; 
    }

  return 0;
}

/* Converts a kilogram weight to a pounds weight.
 *
 * Parameters:
 *  double kilos - a weight in kg
 *
 * Return value:
 *  the equivalent weight in pounds (lbs)
 */
double convert_mass (double kilos)
{
  return kilos * 2.2046;
}


