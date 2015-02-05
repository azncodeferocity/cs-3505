/* Author: Basil Vetas & Lance Petersen
 * Date: February 4, 2015
 * Course: CS 3505
 * Assignment: 4
 * 
 * This class contains the main method for the inventory analysis
 * which generates the report
 *
 */

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <iterator>
#include <boost/foreach.hpp>
#include <boost/range/adaptor/map.hpp>
#include <boost/algorithm/string/trim.hpp>
#include "report.h"

 // BOOST_FOREACH
 // BOOST_STRING_TRIM_HPP
 // BOOST_RANGE_ADAPTOR_MAP_HPP

 /*
  * This in the main entry point for the inventory analysis program.
  * It will print a report containing a list of unstocked products,
  * which do not exist in any warehouse, and also a list of well
  * stocked products, which exist in two or more warehouses.
  *
  */
 int main()
 {
  std::cout << "\n"; // single blank line
  std::cout << "Report by Basil Vetas and Lance Petersen" << std::endl;
  std::cout << "\n"; // single blank line
  std::cout << "Unstocked Products:" << std::endl;
  // determine which products do not exist in any warehouse and print below
  // don't print any other information, and no duplicate products, for example:
  // 0984713912 pizza
  // 0278374752 bagels

  // --------- DO STUFF HERE --------- //

  std::cout << "\n"; // single blank line
  std::cout << "Well-Stocked Products:" << std::endl;
  // determine which products exist in multiple warehouses (positive quantities in at least two warehouses)
  // print out only the UPC and name, for example 
  // 0984712812 mushroom ice cream
  // 0278374652 seaweed cereal

  // --------- DO STUFF HERE --------- //

  std::cout << "\n"; // single blank line

 }









