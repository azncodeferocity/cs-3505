/* Author: Basil Vetas & Lance Petersen
 * Date: February 5, 2015
 * Course: CS 3505
 * Assignment: 4
 * 
 * 
 *
 */

#include <set>
#include <map>
#include <queue>
#include <iterator>
#include "inventory.h"

using namespace std;

/*******************************************************
* inventory member function definitions
***************************************************** */

inventory::inventory()
{

}


/*
 * Default constructor
 *
 */
inventory::inventory(string name, set<food_item> s)
{
  // initialize name of warehouse
  warehouse_name = name;

  // map the upc codes of food items to a queue of those food items
  for (set<food_item>::iterator it = s.begin(); it != s.end(); ++it)
  {
    string upc_code = it->get_upc_code();
    vector<food_item> foods;
    items_in_stock[upc_code] = foods; 
  }
}

/*
 * Destructor
 *
 */
inventory::~inventory()
{

}

/*
 * Helper method to add a food item to this inventory
 *
 */
void inventory::add_item(food_item item, int quantity)
{
  // add 'quantity' of these food items to the queue in our map of queues
  for (int i = 0; i < quantity; i++)
    items_in_stock[item.get_upc_code()].push_back(item);
}

/*
 * Helper method to remove a food item from this inventory
 *
 */
void inventory::remove_item(food_item item, int quantity)
{
  // Remove until the entire quantity request has been removed or there
  // are no more items of that kind in this inventory.
  for (int i = quantity; i > 0; i--)
  {
    // If there are no food item stocked, return
    if(items_in_stock[item.get_upc_code()].size() <= 0)
      return;
    
    // otherwise remove a food item from the front of the vector
    items_in_stock[item.get_upc_code()].erase(items_in_stock[item.get_upc_code()].begin());
  }
}

// /*
//  * Getter for list of stocked foods
//  *
//  */
// set<food_item> inventory::get_stocked_foods()
// {
//   return stocked_foods;
// }

// /*
//  * Getter for list of unstocked foods
//  *
//  */
// set<food_item> inventory::get_unstocked_foods()
// {
//   return unstocked_foods;
// }

/*
 * Updates the inventory each new day by removing 
 * expired items. This may cause some items to 
 * become unstocked.
 */
void inventory::update_inventory()
{

  for (map<string, vector<food_item> >::iterator it = items_in_stock.begin(); it != items_in_stock.end(); ++it)
  {
    for(vector<food_item>::iterator v_it = it->second.begin(); v_it != it->second.end(); ++v_it)
      v_it->update_shelf_life();

    while(it->second.front().get_remaining_days() == 0)
      it->second.erase(it->second.begin());
  }
} 
 
