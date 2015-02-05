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

<<<<<<< HEAD
#include<string>

/*
 * This class represents a food item. It has a UPC code to identify a 
 * type of food item uniquely, a name, a shelf life, and a remaining 
 * life. The shelf life defines how long a particular food item can be 
 * stored. The remaining life tells how many more days from now the 
 * food item can be stored.
 */
class food_item
{
  private:
    std::string UPC_code;  // Uniquely identifies a type of food item
    std::string name;      // The name of this food item.
    int shelf_life;        // How long a food item of this type can be stored
    int remaining_life;    // How much longer this food item can be stored

   public:
    food_item();           //Default constructor
    food_item(std::string upc, int life, std::string n); // Constructor
    
    //Updates this food items remaining life at the start of the next day.
    void update_life();
    
    //Assignment operator copies the data from rhs to this object.
    const food_item operator= (const food_item &rhs);
};

#endif
=======

namespace cs3505
{

  class food_item 
  {
  public:
    food_item(); // public constructor

  private:

  };
}



#endif
>>>>>>> 17ad615197307859c78eafd1a2b789c94f98e77e
