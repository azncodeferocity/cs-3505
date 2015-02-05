Authors: Basil Vetas and Lance Petersen
Date: 2/5/2015
CS 3505



*********** QUESTIONS FOR PETER / TAs ***********

Do we need a namespace?
Do we need a default constructor (for food_item, for example)?
Should we be using namespace std in any files? 
Do we need to override the = (assignment) operator (in food_item, for example)?







*********** PROGRAM NOTES ***********


Functionality of the classes needed for HW #4
Report
  Has the main method.  
  Parses the data. (helper function?)
  Updates the inventories (helper function?)
  Prints the report at the end

Inventory Class
    Has a location/name
    Keeps track of the FoodItems in this inventory

FoodItem Class
   Has a UPC code, shelf life, and name.
   Keeps track of remaining shelf life.
   Essentially stores data about the food item itself



Data structures in classes
Inventory_Analysis
  Keeps a vector of all FoodItems
  Keeps a map of all warehouse names to inventories

Inventory Class
    Has a string for name
    Has a set of queues of FoodItems
        Each FoodItem that is added to an inventory object is put in a 
        queue for that type. Then, when requests are received, it tries
        to take from the queue.

FoodItem Class
   String for UPC code
   Int for shelf life
   Int for remaining shelf life
   String for name




Methods in classes
Inventory_Analysis
  Has a loop that parses the data
  Has a method to handle each type of line
      fooditem, warehouse, start date, receive, request, next day, and end
  Has a method to print out the report or at least generate the info

Inventory Class
    Has a Receive (UPC, quantity) method for when the warehouse 
        receives a fooditem
    Has a Request method (UPC, quantity) to handle requests 
    Has an Update_inventory method()

FoodItem Class
   Constructor
   Update_shelf_life() which is called on each "Next Day".


