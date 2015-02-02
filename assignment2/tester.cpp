#include <iostream>
#include "huge_number.h"

using namespace std;

int main ()
{
  string s = "123";
  huge_number num(s);
  huge_number copy(num);

  cout << "num: " << num.get_value() << endl;   // expects "123"
  cout << "copy: " << copy.get_value() << endl; // expects "123

  string aa = "123";
  string bb = "456";
  huge_number xx(aa);
  huge_number yy(bb);
  huge_number zz;

  zz = xx * yy - xx;

  cout << xx.get_value() << endl;  // xx should not have changed
  cout << yy.get_value() << endl;  // yy should not have changed
  cout << zz.get_value() << endl;

  zz = xx - yy;

  cout << zz.get_value() << endl; // should be zero
  
  huge_number a;  
  huge_number b("5");
  huge_number c("7");
  huge_number d;
  huge_number e;  

  d = b + c;
  e = b * c;

  cout << "a: " << a.get_value() << endl; // expects "0"
  cout << "b: " << b.get_value() << endl; // expects "5"
  cout << "c: " << c.get_value() << endl; // expects "7"
  cout << "d: " << d.get_value() << endl; // expects "12"
  cout << "e: " << e.get_value() << endl; // expects "35" 

  huge_number f("4");
  huge_number g("4");

  //d = f - g; 

  huge_number h("10");
  huge_number i("300");

  //e = h - i;  // test that no negative integer results

  cout << "d: " << d.get_value() << endl; // expects "0"
  cout << "e: " << e.get_value() << endl; // expects "0" 

  huge_number j("17");
  huge_number k("6");
  huge_number l;

  cout << "j: " << j.get_value() << endl; // expects "17"
  cout << "k: " << k.get_value() << endl; // expects "6"

  l = j - k;  

  cout << "l: " << l.get_value() << endl; // expects "11"   

  huge_number z("00003407534");

  cout << "z: " << z.get_value() << endl; // expects "3407534"

  huge_number m("1");
  huge_number n("12");

  cout << "m: " << m.get_value() << endl; // expects "120"
  cout << "n: " << n.get_value() << endl; // expects "12"

  l = m / n;  

  cout << "first div: " << l.get_value() << endl; // expects "10"   

  huge_number o("300000000000000000000000060402");
  huge_number p("2");

  cout << "o: " << o.get_value() << endl; // expects "300000000000000000000000060402"
  cout << "p: " << p.get_value() << endl; // expects "2"

  l = o + p;

  cout << "plus: " << l.get_value() << endl; // expects "300000000000000000000000060404"  

  l = o - p;

  cout << "minus: " << l.get_value() << endl; // expects "300000000000000000000000060400"  

  l = o * p;

  cout << "times: " << l.get_value() << endl; // expects "600000000000000000000000120804"  

  l = o / p;

  cout << "divide: " << l.get_value() << endl; // expects "150000000000000000000000030201"   

  huge_number q("1092348759346739486892354");
  huge_number r("20000000000000000000");

  cout << "q: " << q.get_value() << endl; // expects "892348759346739486892354"
  cout << "r: " << r.get_value() << endl; // expects "2"

  l = q + r;

  cout << "plus: " << l.get_value() << endl; // expects "1 092 368 759 346 739 486 892 354"  

  l = q - r;

  cout << "minus: " << l.get_value() << endl; // expects "1 092 328 759 346 739 486 892 354"  

  l = q * r;

  cout << "times: " << l.get_value() << endl; // expects "21 846 975 186 934 789 737 847 080 000 000 000 000 000 000"  

  l = q / r;

  cout << "divide: " << l.get_value() << endl; // expects "54 617"  

  l = q % r;

  cout << "modulo: " << l.get_value() << endl; // expects "8 759 346 739 486 892 354"  

  huge_number t("103");
  huge_number u("9");

  cout << "t: " << t.get_value() << endl; 
  cout << "u: " << u.get_value() << endl; 

  l = t % u;

  cout << "mod: " << l.get_value() << endl; 



}









