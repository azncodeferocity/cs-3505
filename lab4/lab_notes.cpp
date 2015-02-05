

// --------- VECTORS --------- //

// print vector using Boost
BOOST_FOREACH (int i, vec)
{
  cout << i << " ";
}


// can use copy constructor vec2(vec)


// --------- SETS --------- //

// sets are associative (element 6 is identified with its own value)

// recommended way of finding an element
cont bool is_in = myset.find(9) != myset.end();

if(is_in)
  cout << "FOUND";
else
  cout << "NOT FOUND";

// check if element been inserted
pair<set<int>::iterator, bool> ret;
ret = myset.insert(1);
if(ret.second == false)
  cout << "Not inserted";
else
  cout << "Inserted";

// --------- MAPS --------- //

// associative - k, v pairs 
map<char, int> mymap;
mymap.insert(make_pair(k, v)); // first way to insert
mymap['c'] == 600; // c is key, 600 is value // second way to insert
// use iterators to print out map
cout << it -> first << " +> " << it -> second;\

// find function similair to set
// if find returns and enpoint to map it indicates that
// 
mymap.erase('c'); // key as parameter












