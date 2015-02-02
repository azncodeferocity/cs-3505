#include <iostream>
using namespace std;

int main() {
  int num;
  cout << "Enter the number" << endl;
  cin >> num;
  if (num == 0)
    cout << "No multiplication sine you entered zero" << endl;
  else 
  {
    for(int i  = 1; i <= 10; i++)
    {
      int prod = num*i;
      cout << num << "*" << i << "=" << prod << endl;
    }
  }
}
