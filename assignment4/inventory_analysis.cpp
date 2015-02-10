/* Author: Basil Vetas & Lance Petersen
 * Date: February 5, 2015
 * Course: CS 3505
 * Assignment: 4
 * 
 * This class contains the main method for the inventory analysis
 * which generates the report.
 *
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <iterator>
#include "report.h"
#include "inventory.h"
#include "food_item.h"

using namespace std;

/*
 * This in the main entry point for the inventory analysis program.
 * It will print a report containing a list of unstocked products,
 * which do not exist in any warehouse, and also a list of well
 * stocked products, which exist in two or more warehouses.
 */
int main(int argc, char* argv[])
{

  // if there are the wrong number of arguments, return error message
  if(argc < 2)
    {
      cout << "You have entered too few parameters. Please enter exactly one file name as a parameter." << endl;
      return 1;
    }
  else if(argc > 2)
    {
      cout << "You have entered too many parameters. Please enter exactly one file name as a parameter." << endl;
      return 1;
    }

  report r; // create a new report object to generate our output 

  r.generate_report(argv[1]); // generate the report by scanning through the data file argument

  cout << "\n"; // single blank line
  cout << "Report by Basil Vetas and Lance Petersen" << endl;
  cout << "\n"; // single blank line
  cout << "Unstocked Products:" << endl;
 
  // determine which products do not exist in any warehouse and print below
  // don't print any other information, and no duplicate products

  // get the unstocked products
  map<string, food_item> unstocked = r.get_unstocked_products();
 
  // print out all the unstocked products
  for(map<string, food_item>::iterator inv_it = unstocked.begin();inv_it != unstocked.end(); ++inv_it)
    cout << inv_it->second.to_string() << endl;

  cout << "\n"; // single blank line
  cout << "Well-Stocked Products:" << endl;

  // determine which products exist in multiple warehouses (positive quantities in at least two warehouses)
  // print out only the UPC and name

  // get the well stocked products
  map<string, food_item> well_stocked = r.get_stocked_products();
 
  // print our all the well stocked products
  for(map<string, food_item>::iterator inv_it = well_stocked.begin();inv_it != well_stocked.end(); ++inv_it)
    cout << inv_it->second.to_string() << endl;

  cout << "\n"; // single blank line

  return 0;
}
