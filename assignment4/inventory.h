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

namespace cs3505
{

  class inventory
  {
  public:
    inventory(std::string name); // public constructor
    void update_inventory();     // updates inventory each day
    std::set<food_item> get_stocked_foods();    // getter for stocked foods set

  private:
    std::string warehouse_name; // name of the warehouse
    std::set<food_item> stocked_foods; // set of foods at this warehouse
  };
}

#endif