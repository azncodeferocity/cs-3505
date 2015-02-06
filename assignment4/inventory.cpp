/* Author: Basil Vetas & Lance Petersen
 * Date: February 5, 2015
 * Course: CS 3505
 * Assignment: 4
 * 
 * 
 *
 */

 #include "inventory.h"

/*******************************************************
* inventory member function definitions
***************************************************** */

/*
 * Default constructor
 *
 */
inventory::inventory(std::string name, std::set<food_item> foods)
{
  warehouse_name = name;                  

  unstocked_foods(foods);
}

/*
 * destructor
 *
 */
inventory::~inventory()
{

}

/*
 * Helper method to add a food item to this inventory
 *
 */
void inventory::receive_item(food_item item, int quantity)
{
  //We may need to override the equality function for food_items

  //Check if this food was not stocked in this warehouse before
  if(unstocked_foods.find(item) != unstocked_foods.end())
  {
    stocked_foods.insert(item);
    unstocked_foods.erase(item); // Move the item to stocked foods

    std::queue<food_item> temp; // Create a queue and add it to the map
    items_in_stock.insert (std::pair<std::string, std::queue<food_item> >(item.get_upc_code(), temp));
  }

  std::queue<food_item> temp_queue = items_in_stock.find(item.get_upc_code())->second;
  for (int i= 0; i < quantity; i++)
    temp_queue.push(item);
}

/*
 * Helper method to remove a food item from this inventory
 *
 */
void inventory::request_item(food_item item, int quantity)
{
  //If this item is unstocked, just return
  if(unstocked_foods.find(item) != unstocked_foods.end())
    return;

  //Find this queue in the map
std::queue<food_item> temp_queue = items_in_stock.find(item.get_upc_code)->second;
  // Remove until the entire quantity request has been removed or there
  // are no more items of that kind in this inventory.
  for (int i = quantity; i > quantity; i--)
  {
    temp_queue.pop();

    // If there are no more items, make sets reflect this and return
    if(temp_queue.size() == 0)
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
std::set<food_item> inventory::get_stocked_foods()
{
  return stocked_foods;
}

/*
 * Getter for list of unstocked foods
 *
 */
std::set<food_item> inventory::get_unstocked_foods()
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
  std::pair<std::string, std::queue<food_items> > p;
  BOOST_FOREACH (p , items_in_stock)
  {
    std::queue<food_item> temp_queue = p.second;
    
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
 
