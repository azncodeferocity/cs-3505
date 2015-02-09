/* Author: Basil Vetas & Lance Petersen
 * Date: February 4, 2015
 * Course: CS 3505
 * Assignment: 4
 * 
 * This class generates the report
 *
 */

#include <iostream>
#include <fstream>
#include <stdlib.h>
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

/*
 * Default constructor
 * 
 *
 */
report::report()
{
  // the relative number of days that have passed, initialize to zero
  // days_counter = 0; 
}

/*
 * Destructor
 * 
 *
 */
report::~report()
{

}

/*
 * Reads in the data file passed as a parameter
 * 
 *
 */
void report::generate_report(string filename)
{
  string line; // stores current line  
  ifstream in(filename.c_str()); // file stream object
  bool debug = false;

  // read in the data file and process each line
  while(getline(in, line))
  {
    string delimiter = " ";
    string first_word = line.substr(0, line.find(delimiter));

    if(debug)
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
      food_item f(upc_code, atoi(shelf_life.c_str()), food_name);

      // add the food item to our map with upc code key and food item value
      all_foods[upc_code] = f; 

      // Debugging code
      if(debug)
        for (map<string, food_item>::iterator it = all_foods.begin(); it != all_foods.end(); ++it)
          cout << it->second.to_string() << endl;
      // cout << "**FoodItem: " << f.to_string() << endl;
    }
    else if (first_word == "Warehouse")
    {
      string wh_delim = "Warehouse - ";

      int wh_start = line.find(wh_delim) + wh_delim.length();
      int wh_end = line.length() - wh_start;
      string wh_name = line.substr(wh_start, wh_end);

      // create a new inventory for the given warehouse
      inventory i(wh_name, all_foods);

      // add the inventory to our list of warehouses
      all_warehouses[wh_name] = i; 

      // Debugging code
      // cout << "**Warehouse: " << wh_name << endl;
    }
    else if (first_word == "Start")
    {
      string date_delim = "Start date: ";

      int date_start = line.find(date_delim) + date_delim.length();
      int date_end = line.length() - date_start;
      string date = line.substr(date_start, date_end);

      start_date = date;  // initialize start date

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
      food_item f(upc_code, all_foods[upc_code].get_remaining_days(), food_location);

      all_warehouses[food_location].add_item(f, atoi(quantity.c_str()));

      // Debugging code
      // cout << "**Receive days: " << f.get_remaining_days() << endl;
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
      food_item f(upc_code, all_foods[upc_code].get_remaining_days(), food_location);

      all_warehouses[food_location].remove_item(f, atoi(quantity.c_str()));

      // Debugging code
      // cout << "**Request days: " << f.get_remaining_days() << endl; 
      // cout << "**Request: " << f.to_string() << endl; 
    }
    else if (first_word == "Next")
    {
      for(map<string, inventory>::iterator it = all_warehouses.begin(); it != all_warehouses.end(); ++it)
        it->second.update_inventory();
        // cout << "Inventory: " << it->second.to_string() << endl;
    }
    else if (first_word == "End")
    {
      return;
    }
    else{}
  }
}

/*
 * Getter for all foods
 * 
 *
 */
map<string, food_item> report::get_all_foods()
{
  return all_foods;
}

/*
 * Getter for all inventories
 * 
 *
 */
map<string, inventory> report::get_all_inventories()
{
  return all_warehouses;
}


/* Getter for set of well stocked food items
 * 
 */
map<string, food_item> report::get_stocked_products()
{
  // Create a map of UPC codes to food_items to hold all well stocked foods
  map<string, food_item> well_stocked_foods;

  // Create a map of UPC codes to ints that shows how many locations each food item exists in.
  map<string, int> item_locations;

  // Initialize each item as appearing in 0 locations.
  for(map<string, food_item>::iterator it = all_foods.begin(); it != all_foods.end(); ++it)
    item_locations[it->first] = 0;

  // Loop through every warehouse
  for(map<string,inventory>::iterator it = all_warehouses.begin(); it != all_warehouses.end(); ++it)
  {
    // Get each inventory
    map<string, vector<food_item> > inv = it->second.get_all_foods();

    // For each inventory, loop through all of their food items 
    // Each time an item is in a location, increase the number 
    // in item_locations.
    for(map<string, vector <food_item> >::iterator inv_it = inv.begin(); inv_it != inv.end(); ++inv_it)
    {
      if (inv_it->second.size() > 0)
      {
        map<string, int>::iterator food_it = item_locations.find(inv_it->first);
        if(food_it != item_locations.end())
          food_it->second = food_it->second + 1;
      }
    }
  }

  // For each item that was in more than 1 warehouse, add it to the map of
  // well stocked foods.
  for(map<string, int>::iterator it = item_locations.begin(); it != item_locations.end(); ++it)
    if (it->second > 1)
      well_stocked_foods[it->first] = (all_foods.find(it->first))->second;

  return well_stocked_foods;
}

/* Getter for set of unstocked food items
 * 
 */
map<string, food_item> report::get_unstocked_products()
{
  //Create a map of UPC codes to food_items to hold all unstocked foods
  map<string, food_item> all_unstocked_foods;

  //Set this map equal to the map of all foods
  all_unstocked_foods = all_foods;

  //Loop through every warehouse
  for(map<string,inventory>::iterator it = all_warehouses.begin(); it != all_warehouses.end(); ++it)
  {
    //Get each inventory
    map<string, vector<food_item> > inv = it->second.get_all_foods();

    // For each inventory, loop through all of their food items removing
    // any that are not empty.
    for(map<string, vector <food_item> >::iterator inv_it = inv.begin(); inv_it != inv.end(); ++inv_it)
    {
      //cout<<"Here: ";
      //cout<<inv_it->first<<" ";
      //cout<<inv_it->second.size()<<endl;
      //If the vector of a food item has a size of 0, then it is not unstocked.
      if (inv_it->second.size() != 0)
        all_unstocked_foods.erase(inv_it->first);
    }
  }

  return all_unstocked_foods;
}






