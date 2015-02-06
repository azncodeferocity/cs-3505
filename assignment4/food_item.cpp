/* Author: Basil Vetas & Lance Petersen
 * Date: February 4, 2015
 * Course: CS 3505
 * Assignment: 4
 * 
 * 
 *
 */

#include "food_item.h"

/*******************************************************
* food_item member function definitions
***************************************************** */

/*
 * Default constructor
 *
 */
food_item::food_item()
{

}

/*
 * Main constructor
 *
 */
food_item::food_item(std::string upc, std::string name, int initial_life)
{
  // initialize private member variables
  upc_code = upc;
  food_name = name;
  days_to_expiration = initial_life;
}

/*
 * Destructor
 *
 */
food_item::~food_item()
{

}

/*
 * Helper method
 *
 */
void food_item::update_shelf_life()
{

}

/*
 * Helper method
 *
 */
std::string food_item::get_food_name()
{
  return food_name;
}

/*
 * Helper method
 *
 */
std::string food_item::get_upc_code()
{
  return upc_code;
}

/*
 * Helper method
 *
 */
int food_item::get_remaining_days()
{
  return days_to_expiration;
}

/*
 * Helper method for printing food item to console
 *
 */
std::string food_item::to_string()
{
  return upc_code + " " + food_name;
}

 