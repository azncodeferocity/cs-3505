/* Author: Basil Vetas & Lance Petersen
 * Date: February 5, 2015
 * Course: CS 3505
 * Assignment: 4
 * 
 * 
 *
 */

#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <iterator>
#include "inventory.h"

using namespace std;

/*******************************************************
* inventory member function definitions
***************************************************** */


/*
 * Default constructor
 *
 */
inventory::inventory()
{

}

/*
 * Initialized constructor
 *
 */
inventory::inventory(string name, map<string, food_item> m)
{
  // initialize name of warehouse
  warehouse_name = name;

  // map the upc codes of food items to a vector of those food items
  for (map<string, food_item>::iterator it = m.begin(); it != m.end(); ++it)
  {
    vector<food_item> foods;
    items_in_stock[it->first] = foods; 
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

  // test code
  // for (map<string, vector<food_item> >::iterator it = items_in_stock.begin(); it != items_in_stock.end(); ++it)
  // {
  //   for(vector<food_item>::iterator v_it = it->second.begin(); v_it != it->second.end(); ++v_it)
  //   {
  //     cout << "Food Name: " << v_it->to_string() << endl;
  //     cout << "Food QTY: " << v_it->get_remaining_days() << endl;
  //   }
  // }
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

  // test code
  // for (map<string, vector<food_item> >::iterator it = items_in_stock.begin(); it != items_in_stock.end(); ++it)
  // {
  //   for(vector<food_item>::iterator v_it = it->second.begin(); v_it != it->second.end(); ++v_it)
  //   {
  //     cout << "Food Name: " << v_it->to_string() << endl;
  //     cout << "Food QTY: " << v_it->get_remaining_days() << endl;
  //   }
  // }
}

// /*
//  * Getter for list of all food items
//  *
//  */
map<string, vector<food_item> > inventory::get_all_foods()
{
  return items_in_stock;
}

/*
 * Updates the inventory each new day by removing 
 * expired items. This may cause some items to 
 * become unstocked.
 */
void inventory::update_inventory()
{
  bool debug = false;

  // for each value in the map, iterate over it and get the vector
  for (map<string, vector<food_item> >::iterator it = items_in_stock.begin(); it != items_in_stock.end(); ++it)
  {
    // if the vector has at least one element then loop through it
    if(it->second.size() > 0)
    {
      int expired_item_count = 0;
      // for each vector, iterate over it and update the shelf life (decrement by 1 day)
      for(vector<food_item>::iterator v_it = it->second.begin(); v_it != it->second.end(); ++v_it)
      {
        v_it->update_shelf_life();

        if(v_it->get_remaining_days() == 0)
          expired_item_count++;
        
        // test code
	if(debug)
	  cout << "Remaining Days: " << v_it->get_remaining_days() << endl;
      } 

      // while there are expired items, remove them
      for(int i = expired_item_count; i > 0; i--)
        it->second.erase(it->second.begin()); // remove from beginning index (0)      
    }
  }
} 

/*
 * Helper method for printing food item to console
 *
 */
std::string inventory::to_string()
{
  return warehouse_name;
}





