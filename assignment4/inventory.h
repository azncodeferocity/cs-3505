/* Author: Basil Vetas & Lance Petersen
 * Date: February 5, 2015
 * Course: CS 3505
 * Assignment: 4
 * 
 * 
 *
 */


#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <set>
#include <map>
#include <vector>
#include "food_item.h"

class inventory
{
public:
  inventory();   // default constructor  
  inventory(std::string name, std::map<std::string, food_item> foods);  // initialized constructor  
  ~inventory();                                                         // destructor
  void add_item(food_item item, int quantity);               // adds a food item to this inventory
  void remove_item(food_item item, int quantityt);           // removes a food item from this inventory
  void update_inventory();                                   // removes all expired food items
  std::set<food_item> get_stocked_foods();                   // getter for stocked foods set
  std::set<food_item> get_unstocked_foods();                 // getter for unstocked foods set
  std::string to_string();                                   // For printing an inventory to console

private:
  std::string warehouse_name;                                // name of the warehouse  
  std::map<std::string, std::vector<food_item> > items_in_stock; // map to queues of food items and quantities
};

#endif
