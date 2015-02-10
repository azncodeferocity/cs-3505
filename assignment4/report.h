/* Author: Basil Vetas & Lance Petersen
 * Date: February 5, 2015
 * Course: CS 3505
 * Assignment: 4
 */

#ifndef REPORT_H
#define REPORT_H

#include <string>
#include <vector>
#include <set>
#include "food_item.h"
#include "inventory.h"

/*
 * This class represents warehouse report. It uses the inventory.cpp
 * and food_item.cpp class to generate a warehouse report based on 
 * a provided data file.  It also allows the user to get the list of
 * all foods in the report, all warehouses in the report, and both 
 * the list of unstocked and stocked products at end of all transactions.
 */
class report
{   
public:
  report();           // Default constructor
  ~report();          // Destructor
  void generate_report(std::string filename);       // Reads data file and generates report
  std::map<std::string, food_item> get_all_foods();         // Returns list of all foods
  std::map<std::string, inventory> get_all_inventories();   // Returns list of all warehouses
  std::map<std::string, food_item> get_stocked_products();  // Returns list of well stocked foods
  std::map<std::string, food_item> get_unstocked_products();// Returns list of unstocked foods

private:
  std::string start_date;                           // Start date for the report
  std::map<std::string, food_item> all_foods;       // A map from all upc codes to food items for this report
  std::map<std::string, inventory> all_warehouses;  // A map from all warehouses names to inventories for this report

};

#endif
