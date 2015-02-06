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

/*
 * Default constructor
 *
 */
inventory::inventory(string name, set<food_item> all_foods)
{
  // initialize name of warehouse
  warehouse_name = name;

  // put the list of all the foods in the unstocked set
  for (set<food_item>::iterator it = all_foods.begin(); it != all_foods.end(); ++it)
    unstocked_foods.insert(*it);
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
  // If the food item is not in stock, add it
  if((stocked_foods.find(item) == stocked_foods.end()) && (unstocked_foods.find(item) != unstocked_foods.end()))
  {
    // Move the item to stocked foods and out of unstocked foods
    stocked_foods.insert(item);
    unstocked_foods.erase(item); 

    // create a queue for this food item
    queue<food_item> temp;

    // add temp to a map from UPC codes to queues of food items
    items_in_stock[item.get_upc_code()] = temp;
  }

  // at the end, whether the food item was already stocked or not, add 'quantity' new food items to the queue
  for (int i= 0; i < quantity; i++)
    items_in_stock[item.get_upc_code()].push(item);
}

/*
 * Helper method to remove a food item from this inventory
 *
 */
void inventory::remove_item(food_item item, int quantity)
{
  //If this item is unstocked, just return
  if((stocked_foods.find(item) == stocked_foods.end()) && (unstocked_foods.find(item) != unstocked_foods.end()))
    return;

  // Remove until the entire quantity request has been removed or there
  // are no more items of that kind in this inventory.
  for (int i = quantity; i > 0; i--)
  {
    items_in_stock[item.get_upc_code()].pop();

    // If there are no more items, make sets reflect this and return
    if(items_in_stock[item.get_upc_code()].size() <= 0)
    {
      stocked_foods.erase(item);
      unstocked_foods.insert(item);
      items_in_stock.erase(item.get_upc_code());
      return;
    }
  }
}

/*
 * Getter for list of stocked foods
 *
 */
set<food_item> inventory::get_stocked_foods()
{
  return stocked_foods;
}

/*
 * Getter for list of unstocked foods
 *
 */
set<food_item> inventory::get_unstocked_foods()
{
  return unstocked_foods;
}

/*
 * Updates the inventory each new day by removing 
 * expired items. This may cause some items to 
 * become unstocked.
 */
void inventory::update_inventory()
{

  /*
   * before main: typedef vector<int> YearList;
   *BOOST_FOREACH (YearList yl, m | boost::adaptors::map_values)
   *{
   *  BOOST_FOREACH(int i, yl)
   *    cout<< i << ' ';
   *  cout << endl;
   *}
   */
  pair<string, queue<food_items> > p;
  BOOST_FOREACH (p , items_in_stock)
  {
    queue<food_item> temp_queue = p.second;
    
    BOOST_FOREACH (food_item food, temp_queue)
    {
      food.update_shelf_life();
    }

    while(temp_queue.front().get_remaining_days() == 0)
    {
      temp_queue.pop();
    }

    // If there are no more items, make sets reflect this
    if(temp_queue.size() == 0)
    {
      stocked_foods.erase(item);
      unstocked_foods.insert(item);
      items_in_stock.erase(item.get_upc_code());
    }
  }
} 
 
