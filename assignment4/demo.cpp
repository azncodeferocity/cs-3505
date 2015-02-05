#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <boost/foreach.hpp>
#include <boost/range/adaptor/map.hpp>

// demo from class

using namespace std;

typedef vector<int> YearList;

int main ()
{
  YearList v;
  v.push_back (1);
  v.push_back (1);
  v.push_back (2);
  v.push_back (3);
  v.push_back (5);
  v.push_back (8);
  v.push_back (13);
  v.push_back (19);

  set<int> s;
  

  //for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
  //  cout << *it << endl; 


  for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    s.insert(*it);

  
  for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
    cout << *it << endl;

  map<string,YearList> m;

  YearList w = v;
  w.push_back(21);
  
  m["dog"] = v;
  m["cat"] = w;
  m["bird"].push_back(42);  // Is this legal?
  
  for (map<string,YearList>::iterator it = m.begin(); it != m.end(); ++it)
    cout << it->first << endl;

  BOOST_FOREACH(YearList yl, m | boost::adaptors::map_values)
  {
    BOOST_FOREACH(int i, yl)
      cout << i << ' ';
    
    cout << endl;
  }
} 