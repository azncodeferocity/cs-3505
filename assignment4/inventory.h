/* Author: Basil Vetas & Lance Petersen
 * Date: February 4, 2015
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
#include "food_item.h"

class inventory
{
public:
  inventory(std::string name);                            // default constructor  
  ~inventory();                                           // destructor
  void add_item();                                        // adds a food item to this inventory
  void remove_item();                                     // removes a food item from this inventory
  std::set<food_item> get_stocked_foods();                // getter for stocked foods set
  std::set<food_item> get_unstocked_foods();              // getter for unstocked foods set

private:
  std::string warehouse_name; // name of the warehouse
  std::set<food_item> stocked_foods; // set of foods at this warehouse
  std::set<food_item> unstocked_foods; // set of foods at this warehouse
};

#endif