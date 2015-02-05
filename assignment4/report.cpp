/* Author: Basil Vetas & Lance Petersen
 * Date: February 4, 2015
 * Course: CS 3505
 * Assignment: 4
 * 
 * This class contains the main method for the inventory analysis
 * which generates the report
 *
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <iterator>
#include <boost/foreach.hpp>
#include <boost/range/adaptor/map.hpp>
#include <boost/algorithm/string/trim.hpp>
#include "report.h"
#include "inventory.h"
#include "food_item.h"

using namespace std;

 // BOOST_FOREACH
 // BOOST_STRING_TRIM_HPP
 // BOOST_RANGE_ADAPTOR_MAP_HPP

// Forward declarartion of helper functions
void read_data_file(string filename);

 /*
  * This in the main entry point for the inventory analysis program.
  * It will print a report containing a list of unstocked products,
  * which do not exist in any warehouse, and also a list of well
  * stocked products, which exist in two or more warehouses.
  *
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
  else
    read_data_file(argv[1]);


  cout << "\n"; // single blank line
  cout << "Report by Basil Vetas and Lance Petersen" << endl;
  cout << "\n"; // single blank line
  cout << "Unstocked Products:" << endl;
  // determine which products do not exist in any warehouse and print below
  // don't print any other information, and no duplicate products, for example:
  // 0984713912 pizza
  // 0278374752 bagels


  // test code
  //cs3505::food_item::food_item pizza("0984713912", "pizza", 3);
  //cout << pizza.to_string() << endl;
  // test code



  // --------- DO STUFF HERE --------- //

  cout << "\n"; // single blank line
  cout << "Well-Stocked Products:" << endl;
  // determine which products exist in multiple warehouses (positive quantities in at least two warehouses)
  // print out only the UPC and name, for example 
  // 0984712812 mushroom ice cream
  // 0278374652 seaweed cereal

  // --------- DO STUFF HERE --------- //

  cout << "\n"; // single blank line

  return 0;
 }

/*
 * Reads in the data file passed as a parameter
 * 
 *
 */
 void read_data_file(string filename)
 {
  string line; // stores current line

  ifstream in(filename); // file stream object

  // read in the data file and process each line
  while(getline(in, line))
  {
    cout << line << endl;
  }
 }






