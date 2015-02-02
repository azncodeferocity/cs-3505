#include <iostream>

using namespace std;

/* Pass by value (won't work for value swapping)
 * 
 * 
 */
// void swap(int x, int y)
// {  
//   int temp;
//   temp = x;
//   x = y;
//   y = temp;
// }

// int main()
// {
//   int a = 10, b = 25;
//   cout << "Value of a before swap: " << a << endl;
//   cout << "Value of b before swap: " << b << endl;
//   // ampersand says I want the address of a and of b
//   // so we are passing by pointers to integers, rather
//   // than passing the actual values
//   swap(a, b);
//   cout << "Value of a after swap: " << a << endl;
//   cout << "Value of b after swap: " << b << endl;
// }

/* Function that swaps two int values
 * Using *x and *y rather than x and y
 * allows us to pass pointers (by reference)
 */
// void swap(int *x, int *y)
// {  
//   int temp;
//   temp = *x;
//   *x = *y;
//   *y = temp;
// }

// int main()
// {
//   int a = 10, b = 25;
//   cout << "Value of a before swap: " << a << endl;
//   cout << "Value of b before swap: " << b << endl;
//   // ampersand says I want the address of a and of b
//   // so we are passing by pointers to integers, rather
//   // than passing the actual values
//   swap(&a, &b);
//   cout << "Value of a after swap: " << a << endl;
//   cout << "Value of b after swap: " << b << endl;
// }

/* Now x is a reference variable that points to
 * the parameter passed in
 * 
 */
void swap(int &x, int &y)
{  
  int temp;
  temp = x;
  x = y;
  y = temp;
}

int main()
{
  int a = 10, b = 25;
  cout << "Value of a before swap: " << a << endl;
  cout << "Value of b before swap: " << b << endl;
  // ampersand says I want the address of a and of b
  // so we are passing by pointers to integers, rather
  // than passing the actual values
  swap(a, b);
  cout << "Value of a after swap: " << a << endl;
  cout << "Value of b after swap: " << b << endl;
}






