/* Author: Basil Vetas & Lance Petersen
 * Date: February 4, 2015
 * Course: CS 3505
 * Assignment: 4
 * 
 * 
 *
 */

#ifndef FOOD_ITEM_H
#define FOOD_ITEM_H

#include <string>

/*
 * This class represents a food item. It has a UPC code to identify a 
 * type of food item uniquely, a name, a shelf life, and a remaining 
 * life. The shelf life defines how long a particular food item can be 
 * stored. The remaining life tells how many more days from now the 
 * food item can be stored.
 */
class food_item
{   
public:
  food_item();           //Default constructor
  food_item(std::string upc, std::string name, int initial_life); // Constructor  
  ~food_item(); // Destructor
  
  //Updates this food items remaining life at the start of the next day.
  void update_shelf_life();
  std::string get_food_name();  // getter for food name
  std::string get_upc_code();   // getter for upc code
  int get_remaining_days();     // getter for days until expiration
  std::string to_string();      // for printing a food item to console

private:
  std::string upc_code;    // Uniquely identifies a type of food item
  std::string food_name;        // The name of this food item.
  int days_to_expiration;  // How long a food item of this type can be stored, initialize to shelf life
};


#endif
