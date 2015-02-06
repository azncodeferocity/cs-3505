/* Author: Basil Vetas & Lance Petersen
 * Date: February 4, 2015
 * Course: CS 3505
 * Assignment: 4
 * 
 * 
 *
 */

#ifndef REPORT_H
#define REPORT_H

#include <string>
#include <vector>
#include <set>
#include "food_item.h"
#include "inventory.h"

/*
 * This class represents a food item. It has a UPC code to identify a 
 * type of food item uniquely, a name, a shelf life, and a remaining 
 * life. The shelf life defines how long a particular food item can be 
 * stored. The remaining life tells how many more days from now the 
 * food item can be stored.
 */
class report
{   
public:
  report();           //Default constructor
  ~report();          // Destructor
  void generate_report(std::string filename);
  std::set<food_item> get_stocked_products();
  std::set<food_item> get_unstocked_products();

private:
  std::map<std::string, food_item> all_foods;     // a map from all upc codes to food items for this report
  std::set<inventory> all_warehouses;             // a set of all the warehouses for this report
  std::set<food_item> all_stocked_foods;          // a set of all the stocked items at end of report
  std::set<food_item> all_unstocked_foods;        // a set of all the unstocked items at end of report 

};


#endif