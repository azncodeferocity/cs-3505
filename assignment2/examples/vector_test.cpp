#include <iostream>
#include "vector.h"

using namespace std;

int main ()
{
  vector a(5, 6);
  vector b(3, 4);
  vector c(0, 0);

  cout << a.get_x() << " " << a.get_y() << endl;
  cout << b.get_x() << " " << b.get_y() << endl;

  c = a + b;
  
  cout << c.get_x() << " " << c.get_y() << endl;
}