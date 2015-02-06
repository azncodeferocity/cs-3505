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
  // food_item::food_item pizza("0984713912", 3, "pizza");
  // cout << pizza.to_string() << endl;
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
    string delimiter = " ";
    string first_word = line.substr(0, line.find(delimiter));

    cout << line << endl;
    cout << first_word << endl;

    if(first_word == "FoodItem")
    {
      // delimiters for finding correct strings
      string upc_delim = "UPC Code: ";
      string name_delim = "Name: ";
      string sf_delim = "Shelf life: ";

      // get start and end index then parse the UPC code
      int upc_start = line.find(upc_delim) + upc_delim.length();
      int upc_end = line.find(delimiter, upc_start) - upc_start;
      string upc_code = line.substr(upc_start, upc_end);

      // get start and end index then parse the shelf life
      int life_start = line.find(sf_delim) + sf_delim.length();
      int life_end = line.find(delimiter, life_start) - life_start;
      int shelf_life = stoi(line.substr(life_start, life_end));
      
      // get start and end index then parse the food name
      int name_start = line.find(name_delim) + name_delim.length();
      int name_end = line.length() - name_start;
      string name = line.substr(name_start, name_end);

      // parse the line and create a food item to store the data
      food_item::food_item f(upc_code, shelf_life, name);      

      cout << f.to_string() << endl;
    }



  }
 }






