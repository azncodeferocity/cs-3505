/* Author: Basil Vetas
 * Date: January 17, 2015
 * Course: CS 3505
 * Version: 1.0
 *
 * A class named huge_number whose objects exactly represent non-negative integers 
 * of an arbitrary number of digits.
 *
 * This class supports the following operations:
 * -Equality
 * -Addition
 * -Subtraction
 * -Multiplication
 * -Division
 * -Modulo
 *
 * To compile:  g++ huge_number.cpp
 * To run:      ./a.out
 */
#include <string>
#include "huge_number.h"

using namespace std;

/* A public default constructor that initializes the object to represent 0
 *
 * The constructor will be used like this: 
 *    huge_number num;
 */ 
huge_number::huge_number()
{
  number = "0"; 
}

/* A public constructor that takes a single string parameter representing 
 * a non-negative integer.  You may assume the string contains only digits.
 *
 * The constructor will be used like this:
 *    string s = "123";
 *    huge_number num(s);
 *
 * @param : _num -- the string represented as a huge_number
 */ 
huge_number::huge_number(string _num)
{
  // Helper method to remove any leading zeros before assigning to 'number'
  number = remove_zeros(_num);  
}

/* A public copy constructor
 *
 * The constructor will be used like this:
 *    huge_number num("123");
 *    huge_number copy(num);
 *  
 * @param : huge_number& other -- the huge_number object to be copied
 */ 
huge_number::huge_number (const huge_number& other) 
{
  number = other.number;
}

/* A public accessor method named get_value that returns the string
 * representation of the number within the object.  
 * 
 * @return : the string representation of this huge_number
 */ 
string huge_number::get_value() const
{
  return number;
}

/* Override equals (assignment) operator
 *
 * @return : the huge_number result after assignment
 */ 
huge_number& huge_number::operator= (const huge_number & rhs)
{  
  number = rhs.number;
  return *this;
}

/* Override add operator
 *
 * @return : the huge_number result after addition
 */ 
const huge_number huge_number::operator+ (const huge_number & rhs) const
{ 
  huge_number result(add(number, rhs.number));
  return result;
}

/* Override subtract operator
 *  
 * @return : the huge_number result after subtraction
 */ 
const huge_number huge_number::operator- (const huge_number & rhs) const
{
  huge_number result(subtract(number, rhs.number));
  return result;
}

/* Override multiply operator
 *
 * @return : the huge_number result after multiplication
 */ 
const huge_number huge_number::operator* (const huge_number & rhs) const
{
  huge_number result(multiply(number, rhs.number));
  return result;
}

/* Override divide operator
 *
 * @return : the huge_number result after division
 */ 
const huge_number huge_number::operator/ (const huge_number & rhs) const
{
  huge_number result(divide(number, rhs.number));
  return result;
}

/* Override modulo operator
 *  
 * @return : the huge_number result after modulo
 */ 
const huge_number huge_number::operator% (const huge_number & rhs) const
{
  huge_number result(mod(number, rhs.number));
  return result;
}



/*------------------------------- Private Helper Methods ------------------------------- */



/*
 * Adds two numbers stored in strings, building a string result.
 * 
 * Citation: Peter Jensen, CS 3505 Spring 2015
 *
 * @return : the result after addition
 */
string huge_number::add (string left, string right) const
{
  // Build up a string to contain the result.
  
  string result = "";

  // Work right to left.

  int left_pos  = left.length()  - 1;
  int right_pos = right.length() - 1;

  int carry = 0;

  // Loop, adding columns until no more digits remain.

  while (left_pos >= 0 || right_pos >= 0 || carry > 0)
  {
    // Get the digit from each string, or 0 if none.

    int left_digit  = left_pos  >= 0 ? left[left_pos--]   - '0' : 0;
    int right_digit = right_pos >= 0 ? right[right_pos--] - '0' : 0;

    // Calcuate the sum of the digits.

    int sum = left_digit + right_digit + carry;
    carry = sum / 10;
    sum   = sum % 10 + '0';

    // Put the sum into the new string (at the left side)

    result.insert (0, 1, static_cast<char>(sum) );
    
  }

  // Helper method to remove any leading zeros before returning
  return remove_zeros(result);
}

/*
 * Subtracts the second parameter from the first parameter,
 * stored in strings, building a string result.
 *
 * @return : the result after subtraction
 */
string huge_number::subtract (string left, string right) const
{
  string result = "";

  // if the left side is not bigger, then they are either equal 
  // or the right is bigger, so we want to return 0 (no negative results)
  if(!(is_bigger(left, right)))
    return "0";

  // Work right to left (indices).

  int left_pos  = left.length()  - 1;
  int right_pos = right.length() - 1;

  int carry = 0;

  // Loop, subtracting columns until no more digits remain in left.
  while (left_pos >= 0)
  {
    // Get the digit from each string, or 0 if none.

    int left_digit  = left_pos  >= 0 ? left[left_pos--]   - '0' : 0;
    int right_digit = right_pos >= 0 ? right[right_pos--] - '0' : 0;

    // Calcuate the difference of the digits.
    int difference = left_digit - right_digit - carry;
    if(difference < 0)  // if negative, we need to carry
    {
      difference += 10;
      carry = 1;
    }
    else  carry = 0; // else reset carry to 0

    difference += '0';

    // Put the difference into the new string (at the left side)
    // Note: difference should always be between 0-9

    result.insert(0, 1, static_cast<char>(difference));
    
  }

  // Helper method to remove any leading zeros before returning
  return remove_zeros(result);
}

/*
 * Multiplies two numbers stored in strings, building a string result.
 * The algorithm is long multiplication, starting with the most significant
 * digit of the multiplier.
 * 
 * Citation: Peter Jensen, CS 3505 Spring 2015
 *
 * @return : the result after multiplication
 */
string huge_number::multiply (string left, string right) const
{
  string result = "0";

  int right_pos = 0;

  while (right_pos < right.length())
  {
    result.append("0");  // Multiply the product by 10.

    int right_digit = right[right_pos++] - '0';

    for (int i = 0; i < right_digit; i++)
      result = add(result, left);
  }

  // Helper method to remove any leading zeros before returning
  return remove_zeros(result);
}

/*
 * Divides the first parameter by second parameter,
 * stored in strings, building a string result.
 * 
 * @return : the result after division
 */
string huge_number::divide (string left, string right) const
{
  string result = "0";

  int left_pos = 0;
  string carry = "0";

  while (left_pos < left.length())
  {
    string count = "0";
    carry = multiply(carry, "10"); // Multiply the remainder by 10.

    // get the left-most digit
    string left_digit = add(carry, left.substr(left_pos++, 1));

    // while the divisor (right) is less than or equal
    // to (not bigger than) the left digit, continue
    // subtracting divisor from the left digit and increment    
    while(!(is_bigger(right, left_digit)))
    {            
      // subtract right from left_digit
      left_digit = subtract(left_digit, right);

      // increment result by 1 after subtracting
      count = add(count, "1");
    }

    // mod it to get remainder 
    carry = left_digit;        

    // append quotient to result from the right
    result += count;
  }

  // Helper method to remove any leading zeros before returning
  return remove_zeros(result);
}

/*
 * Mods the first parameter by second parameter,
 * stored in strings, building a string result.
 *
 * @return : the result after modulo
 */
string huge_number::mod (string left, string right) const
{
  string result = "0";

  int left_pos = 0;
  string carry = "0";

  while (left_pos < left.length())
  {
    carry = multiply(carry, "10"); // Multiply the remainder by 10.

    // get the left-most digit
    string left_digit = add(carry, left.substr(left_pos++, 1));

    // while the divisor (right) is less than or equal
    // to (not bigger than) the left digit, continue
    // subtracting divisor from the left digit and increment    
    while(!(is_bigger(right, left_digit)))
    {            
      // subtract right from left_digit
      left_digit = subtract(left_digit, right);
    }

    // mod it to get remainder 
    carry = left_digit;        
  }

  // carry after division ends is the remainder
  result = carry;

  // Helper method to remove any leading zeros before returning
  return remove_zeros(result);
}

/*
 * Compares the first and second paramter
 * 
 * Invariant: assumes the parameters are strings of non-negative integers
 *
 * @return : true if the first param is bigger, false otherwise
 */
bool huge_number::is_bigger (string left, string right) const
{
  bool left_is_bigger = false;
  if(left.length() > right.length())      // if 'left' has more digits then it is bigger
    left_is_bigger = true;
  else if(left.length() < right.length()) // if 'left' has less digits then it is smaller
    left_is_bigger = false;
  else                                    // o/w must compare digit by digit (from the left)      
  { 
    // Start indices at 0
    int left_pos  = 0;
    int right_pos = 0; 

    // Loop, comparing numbers at each position
    while (left_pos < left.length())
    {
      // Get the digit from each string, or 0 if none.
      int left_digit  = left[left_pos++]   - '0';
      int right_digit = right[right_pos++] - '0';

      // if the far left of 'left' is bigger, then 'left' is bigger
      if(left_digit > right_digit)
      {
        left_is_bigger = true;
        break;
      }
      else if(left_digit < right_digit)
      {
        left_is_bigger = false;
        break;
      }
    }
  }
  
  return left_is_bigger;
}

/*
 * Takes in a string parameter and strips off any leading zeros then
 * returns the new string (should be the same integer value)
 *
 * @return : a string of integers without leading zeros
 */
string huge_number::remove_zeros (string num) const
{
  while (num.length() > 0 && num[0] == '0')
    num.erase(0, 1);

  // If the string is empty, it's a 0.  Put one back.
  if (num.length() == 0)
    num = "0";

  return num;
}





