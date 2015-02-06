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

set<food_item> all_foods;      // a list of all the unique food items for this report
set<inventory> all_warehouses; // a list of all the unique warehouses for this report

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

    if (first_word == "FoodItem")
    {
      // delimiters for finding correct strings
      string upc_delim = "UPC Code: ";
      string sf_delim = "Shelf life: ";
      string name_delim = "Name: ";

      // UPC CODE: get start and end index then parse the UPC code
      int upc_start = line.find(upc_delim) + upc_delim.length();
      int upc_end = line.find(delimiter, upc_start) - upc_start;
      string upc_code = line.substr(upc_start, upc_end);

      // SHELF LIFE: get start and end index then parse the shelf life
      int life_start = line.find(sf_delim) + sf_delim.length();
      int life_end = line.find(delimiter, life_start) - life_start;
      string shelf_life = line.substr(life_start, life_end);
      
      // FOOD NAME: get start and end index then parse the food name
      int name_start = line.find(name_delim) + name_delim.length();
      int name_end = line.length() - name_start;
      string food_name = line.substr(name_start, name_end);

      // parse the line and create a food item to store the data
      food_item::food_item f(upc_code, stoi(shelf_life), food_name);

      // add the food item to our set of all food items
      all_foods.insert(f);

      // Debugging code
      // cout << "**FoodItem: " << f.to_string() << endl;
    }
    else if (first_word == "Warehouse")
    {
      string wh_delim = "Warehouse - ";

      int wh_start = line.find(wh_delim) + wh_delim.length();
      int wh_end = line.length() - wh_start;
      string wh_name = line.substr(wh_start, wh_end);

      // create a new inventory for the given warehouse
      inventory::inventory i(wh_name, all_foods);

      // add the inventory to our list of warehouses
      all_warehouses.insert(i);

      // Debugging code
      // cout << "**Warehouse: " << wh_name << endl;
    }
    else if (first_word == "Start")
    {
      string date_delim = "Start date: ";

      int date_start = line.find(date_delim) + date_delim.length();
      int date_end = line.length() - date_start;
      string date = line.substr(date_start, date_end);

      // initialize counter to 0

      // Debugging code
      // cout << "**Start Date: " << date << endl;
    }
    else if (first_word == "Receive:")
    {
      // UPC CODE: get start and end index then parse the UPC code
      string upc_delim = "Receive: ";
      int upc_start = line.find(upc_delim) + upc_delim.length();
      int upc_end = line.find(delimiter, upc_start) - upc_start;
      string upc_code = line.substr(upc_start, upc_end);

      // QUANTITY: get start and end index then parse the quantity
      string qty_delim = upc_code;
      int qty_start = line.find(qty_delim) + qty_delim.length() + 1; // plus 1 to account for extra space
      int qty_end = line.find(delimiter, qty_start) - qty_start;
      string quantity = line.substr(qty_start, qty_end);

      // WAREHOUSE NAME: get start and end index then parse the warehouse name
      string name_delim = upc_code + " " + quantity;
      int wh_start = line.find(name_delim) + name_delim.length() + 1; // plus 1 to account for extra space
      int wh_end = line.length() - wh_start;
      string food_location = line.substr(wh_start, wh_end);

      // parse the line and create a food item to store the data
      // food_item::food_item f(upc_code, stoi(????), food_location);

      // Debugging code
      // cout << "**Receive: " << f.to_string() << endl;
    }
    else if (first_word == "Request:")
    {
            // UPC CODE: get start and end index then parse the UPC code
      string upc_delim = "Request: ";
      int upc_start = line.find(upc_delim) + upc_delim.length();
      int upc_end = line.find(delimiter, upc_start) - upc_start;
      string upc_code = line.substr(upc_start, upc_end);

      // QUANTITY: get start and end index then parse the quantity
      string qty_delim = upc_code;
      int qty_start = line.find(qty_delim) + qty_delim.length() + 1; // plus 1 to account for extra space
      int qty_end = line.find(delimiter, qty_start) - qty_start;
      string quantity = line.substr(qty_start, qty_end);

      // WAREHOUSE NAME: get start and end index then parse the warehouse name
      string name_delim = upc_code + " " + quantity;
      int wh_start = line.find(name_delim) + name_delim.length() + 1; // plus 1 to account for extra space
      int wh_end = line.length() - wh_start;
      string food_location = line.substr(wh_start, wh_end);

      // parse the line and create a food item to store the data
      // food_item::food_item f(upc_code, stoi(????), food_location);

      // Debugging code
      // cout << "**Request: " << f.to_string() << endl; 
    }
    else if (first_word == "Next")
    {
      // decrement counter
    }
    else if (first_word == "End")
    {
      // return
    }
    else
    {

    }

  }

 }






