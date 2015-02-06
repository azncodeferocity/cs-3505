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
#include <queue>
#include "food_item.h"

class inventory
{
public:
  inventory(std::string name, std::set<food_item> foods);    // default constructor  
  ~inventory();                                              // destructor
  void receive_item(food_item item, int quantity);           // adds a food item to this inventory
  void request_item(food_item item, int quantityt);          // removes a food item from this inventory
  void update_inventory();                                   // removes any expired food items
  std::set<food_item> get_stocked_foods();                   // getter for stocked foods set
  std::set<food_item> get_unstocked_foods();                 // getter for unstocked foods set

private:
  std::string warehouse_name;                                // name of the warehouse
  std::set<food_item> stocked_foods;                         // set of foods at this warehouse
  std::set<food_item> unstocked_foods;                       // set of foods not at this warehouse
  std::map<std::string, std::queue<food_item> > items_in_stock; // map of queues of food items
};

#endif
