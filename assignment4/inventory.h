/* Author: Basil Vetas & Lance Petersen
 * Date: February 5, 2015
 * Course: CS 3505
 * Assignment: 4
 */

#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <map>
#include <vector>
#include "food_item.h"

/*
 * This class represent the inventory of food items stored at a single warehouse.
 * It uses the food_item.cpp class and keeps track of all transactions that take
 * place at that warehouse. This includes adding and removing items from the inventory,
 * and also removing expired items from the inventory. The user may return a set of all
 * the foods in the warehouse at the end of a report. 
 */
class inventory
{
public:
  inventory();   // Default constructor  
  inventory(std::string name, std::map<std::string, food_item> foods);  // Initialized constructor  
  ~inventory();                                                         // Destructor
  void add_item(food_item item, int quantity);               // Adds a food item to this inventory
  void remove_item(food_item item, int quantityt);           // Removes a food item from this inventory
  void update_inventory();                                   // Removes all expired food items
  std::map<std::string, std::vector<food_item> > get_all_foods();        // Returns map of all foods 
  std::string to_string();                                   // For printing an inventory to console

private:
  std::string warehouse_name;                                // Name of the warehouse  
  std::map<std::string, std::vector<food_item> > items_in_stock; // Map to queues of food items and quantities
};

#endif
