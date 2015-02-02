#include "vector.h"
#include <iostream>

vector::vector (int _x, int _y)
{
  x = _x;
  y = _y;

  std::cout << "In the vector constructor." << std::endl;
}

vector::~vector ()
{
  std::cout << "In the vector destructor." << std::endl;
}

vector vector::operator+ (const vector & rhs) const
{
  vector result_yay (x + rhs.x, y + rhs.y);

  return result_yay;
}

int vector::get_x ()
{
  return x;
}

int vector::get_y ()
{
  return y;
}