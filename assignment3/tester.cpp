/* Author: Basil Vetas
 * Date: January 26, 2015
 * Course: CS 3505
 * Assignment: 3
 * 
 * This is a tester similar to the tester written in class.  It reads
 * words from a text file, then adds the words to two sets: A built-in
 * set class, and our wordset class.  After reading the file, it
 * prints out all the words stored in the STL set object.  At the end
 * of the test, it prints out the sizes of both sets to see that they
 * are the same.
 *
 * After the test completes, I make sure the local variabls are properly
 * cleaned up.
 *
 * If the comments wrap lines, widen your emacs window.
 *
 * Peter Jensen
 * January 22, 2015
 */

#include <iostream>
#include <fstream>
#include <set>
#include <iterator>
#include "wordset.h"
#include "node.h"

using namespace std;

// Note:  Our classes were declared in a cs3505 namepsace.
//        Instead of 'using namespace cs3505', I qualify the class names below with cs3505::

int main ()
{
  bool tests_passed = true;

  // Open up another block.  This way, when the block ends,
  // variables local to the block will be destroyed, but main
  // will still be running.  (Did you know that you can open
  // up a block at any time to control local variable scope and
  // lifetime?)
  
  /* Test 0: Add size
   *
   * Tests that our wordset and a regular set have the same size after
   * adding the same elements from Yankee.txt file (test provided by Peter Jensen)
   *
   */
  {
    // Create the two sets.  Declaring the local variables constructs the objects.
  
    set<string>      stl_set_of_words;  // The built-in set class - no constructor parameters.

    cs3505::wordset  our_set_of_words(1000);  // Our set class, with a hashtable of 1000 slots.    

    // Open the file stream for reading.  (We'll be able to use it just like
    //   the keyboard stream 'cin'.)

    ifstream in("Yankee.txt");

    // Loop for reading the file.  Note that it is controlled
    //   from within the loop (see the 'break').
    
    while (true)
    {
      // Read a word (don't worry about punctuation)
      
      string word;
      in >> word;

      // If the read failed, we're probably at end of file
      //   (or else the disk went bad).  Exit the loop.
      
      if (in.fail())
        break;

      // Word successfully read.  Add it to both sets.
      
      stl_set_of_words.insert(word);
      our_set_of_words.add(word);            
    }

    // Close the file.

    in.close();

    if(stl_set_of_words.size() != our_set_of_words.size())
    {
      cout << "ERROR: The size of your wordset and the size of the regular set are not equal, but should be." << endl;
      tests_passed = false;
    }

    // Print out the words found in the STL set.  I do this to show
    //   students how to get at the entries in an STL object.  For
    //   more examples, look up 'STL iterator examples'.
    // Notice that the iterator object 'it' acts like a pointer, but
    //   it is not a pointer.  (Bad, bad, bad design choice, but not mine!)
    // Feel free to comment this out.
  
    // for (set<string>::iterator it = stl_set_of_words.begin(); it != stl_set_of_words.end(); it++)
    // {
    //   string s = *it;
    //   cout << s << endl;
    // }

    // Print out the number of words found in each set.
    
    // cout << endl;
    // cout << "STL set contains " << stl_set_of_words.size() << " unique words.\n";
    // cout << "Our set contains " << our_set_of_words.size() << " unique words.\n";
    // cout << endl;

    // Done.  Notice that this code block ends below.  Any local
    // variables declared within this block will be automatically
    // destroyed.  Local objects will have their destructors
    // called.

  }

  /************************** My Tests **************************/

  /* Test 1: Size
   *
   * Tests if a wordset returns the correct size
   *
   */
  {
    cs3505::wordset  word_set(1000);  // Our set class, with a hashtable of 1000 slots.    

    word_set.add("Hello");
    word_set.add("Goodbye");
    word_set.add("So Long");
    word_set.add("Farewell");

    if(word_set.size() != 4)
    {
      cout << "ERROR: Size of wordset should equal 4 but it does not." << endl;
      tests_passed = false;
    }
  }

  /* Test 2: Contains
   *
   * Tests if wordset.contains returns the correct result
   *
   */
  {
    cs3505::wordset  word_set(1000);  // Our set class, with a hashtable of 1000 slots.    

    word_set.add("Hello");
    word_set.add("Goodbye");
    word_set.add("So Long");
    word_set.add("Farewell");

    if(!(word_set.contains("Hello")))
    {
      cout << "ERROR: The contains method should have returned true but it did not." << endl;
      tests_passed = false;
    }

    if(!(word_set.contains("Goodbye")))
    {
      cout << "ERROR: The contains method should have returned true but it did not." << endl;
      tests_passed = false;
    }

    if(!(word_set.contains("So Long")))
    {
      cout << "ERROR: The contains method should have returned true but it did not." << endl;
      tests_passed = false;
    }

    if(!(word_set.contains("Farewell")))
    {
      cout << "ERROR: The contains method should have returned true but it did not." << endl;
      tests_passed = false;
    }
  }

  /* Test 3: Add contents
   *
   * Tests that our wordset and a regular set have the same contents after
   * adding the same elements from Yankee.txt file 
   *
   */
  {
    // Create the two sets.  Declaring the local variables constructs the objects.
  
    set<string>      stl_set_of_words;  // The built-in set class - no constructor parameters.

    cs3505::wordset  our_set_of_words(1000);  // Our set class, with a hashtable of 1000 slots.    

    // Open the file stream for reading.  (We'll be able to use it just like
    //   the keyhboard stream 'cin'.)

    ifstream in("Yankee.txt");

    // Loop for reading the file.  Note that it is controlled
    //   from within the loop (see the 'break').
    
    while (true)
    {
      // Read a word (don't worry about punctuation)
      
      string word;
      in >> word;

      // If the read failed, we're probably at end of file
      //   (or else the disk went bad).  Exit the loop.
      
      if (in.fail())
        break;

      // Word successfully read.  Add it to both sets.
      
      stl_set_of_words.insert(word);
      our_set_of_words.add(word);            
    }

    // Close the file.

    in.close();

    // for every word in the normal set
    for (set<string>::iterator it = stl_set_of_words.begin(); it != stl_set_of_words.end(); it++)
    {
      string s = *it;

      // if our set doesn't contain a word
      if(!(our_set_of_words.contains(s)))
      {
        cout << "ERROR: Add method failed, the regular set contains a word that is not in the wordset." << endl;
        tests_passed = false;
      }
    }
  }

  /* Test 4: Get Elements Size
   *
   * Tests if the new array has the correct size after calling get_elements() on our wordset
   * with n parameter less than, greater than, and equal to the size of our wordset
   *
   */
  {
    cs3505::wordset  word_set(1000);  // Our set class, with a hashtable of 1000 slots.    

    word_set.add("Hello");
    word_set.add("Goodbye");
    word_set.add("So Long");
    word_set.add("Farewell");

    // ---------- n Equal To size ---------- //

    // Create array with n equal to wordset size
    string *same = new string[word_set.size()];

    // initialize array to double newline strings
    for(int i = 0; i < word_set.size(); i++)
      same[i] = "\n\n";

    // get the elements from the wordset
    word_set.get_elements(same, word_set.size());

    int equal_to_count = 0;

    // iterate through array and count non-null elements
    for(int i = 0; i < word_set.size(); i++)
    {
      if(same[i] != "\n\n")
        equal_to_count++;
    }

    if(equal_to_count != word_set.size())
    {
      cout << "ERROR: The get_elements method did not return the correct number of elements when n equals size" << endl;
      tests_passed = false;
    }

    // ---------- n Less Than size ---------- //

    // Create array with n equal to wordset size
    string *less = new string[word_set.size()];

    // initialize array to double newline strings
    for(int i = 0; i < word_set.size(); i++)
      less[i] = "\n\n";

    // get the elements from the wordset
    word_set.get_elements(less, (word_set.size()-2));

    int less_than_count = 0;

    // iterate through array and count non-null elements
    for(int i = 0; i < word_set.size(); i++)
    {
      if(less[i] != "\n\n")
        less_than_count++;
    }

    if(less_than_count != (word_set.size()-2))
    {
      cout << "ERROR: The get_elements method did not return the correct number of elements when n less than size" << endl;
      tests_passed = false;
    }

    // ---------- n Greater Than size ---------- //

    // Create array with n equal to wordset size
    string *more = new string[word_set.size()];

    // initialize array to double newline strings
    for(int i = 0; i < word_set.size(); i++)
      more[i] = "\n\n";

    // get the elements from the wordset
    word_set.get_elements(more, (word_set.size()+2));

    int greater_than_count = 0;

    // iterate through array and count non-null elements
    for(int i = 0; i < word_set.size(); i++)
    {      
      if(more[i] != "\n\n")
        greater_than_count++;
    }

    if(greater_than_count != (word_set.size()))
    {
      cout << "ERROR: The get_elements method did not return the correct number of elements when n greater than size" << endl;
      tests_passed = false;
    }

    delete [] same;
    delete [] less;
    delete [] more;
  }

  /* Test 5: Get Elements Contents
   *
   * Tests if the new array has the correct contents after calling get_elements() on our wordset
   * with n parameter less than, greater than, and equal to the size of our wordset
   *
   */
  {
    cs3505::wordset  word_set(1000);  // Our set class, with a hashtable of 1000 slots.    

    word_set.add("Hello");
    word_set.add("Goodbye");
    word_set.add("So Long");
    word_set.add("Farewell");

    // ---------- n Equal To size ---------- //

    // Create array with n equal to wordset size
    string *same = new string[word_set.size()];

    // initialize array to double newline strings
    for(int i = 0; i < word_set.size(); i++)
      same[i] = "\n\n";

    // get the elements from the wordset
    word_set.get_elements(same, word_set.size());

    // iterate through array and count non-null elements
    for(int i = 0; i < word_set.size(); i++)
    {
      // if the wordset doesn't contain the element in the array
      if(!(word_set.contains(same[i])))
      {
        cout << "ERROR: The array passed to get_elements contains a string not in the wordset when n equals size" << endl;
        tests_passed = false;
      }
    }

    // ---------- n Less Than size ---------- //

    // Create array with n equal to wordset size
    string *less = new string[word_set.size()];

    // initialize array to double newline strings
    for(int i = 0; i < word_set.size(); i++)
      less[i] = "\n\n";

    // get the elements from the wordset
    word_set.get_elements(less, word_set.size()-2);

    // iterate through array and count non-null elements
    for(int i = 0; i < word_set.size(); i++)
    {
      // if the wordset doesn't contain the element in the array and it is not null
      if(!(word_set.contains(less[i])) && (less[i] != "\n\n"))
      {
        cout << "ERROR: The array passed to get_elements contains a string not in the wordset when n less than size" << endl;
        tests_passed = false;
      }
    }

    // ---------- n Greater Than size ---------- //

    // Create array with n equal to wordset size
    string *more = new string[word_set.size()];

    // initialize array to double newline strings
    for(int i = 0; i < word_set.size(); i++)
      more[i] = "\n\n";

    // get the elements from the wordset
    word_set.get_elements(more, word_set.size()+2);

    // iterate through array and count non-null elements
    for(int i = 0; i < word_set.size(); i++)
    {
      // if the wordset doesn't contain the element in the array
      if(!(word_set.contains(more[i])))
      {
        cout << "ERROR: The array passed to get_elements contains a string not in the wordset when n greater than size" << endl;
        tests_passed = false;
      }
    }

    delete [] same;
    delete [] less;
    delete [] more;
  }

  /* Test 6: Copy Constructor Size
   *
   * Tests if the original wordset and copy wordset have the same size 
   * after using the copy constructor (and thus the assignment operator)
   *
   */
  {
    cs3505::wordset  our_set_of_words(1000);  // Our set class, with a hashtable of 1000 slots.    

    ifstream in("Yankee.txt");

    // Loop for reading the file.  Note that it is controlled
    //   from within the loop (see the 'break').
    
    while (true)
    {
      // Read a word (don't worry about punctuation)
      
      string word;
      in >> word;

      // If the read failed, we're probably at end of file
      //   (or else the disk went bad).  Exit the loop.
      
      if (in.fail())
        break;

      // Word successfully read.  Add it to wordset.
      our_set_of_words.add(word);            
    }

    // Close the file.

    in.close();

    // Copy original wordset into new wordset
    cs3505::wordset  copy_set_of_words(our_set_of_words); // A copy of our set of words

    if(copy_set_of_words.size() != our_set_of_words.size())
    {
      cout << "ERROR: The copy constructor failed to create a copy with the same size as the set it was copied from." << endl;
      tests_passed = false;
    }
  }

  /* Test 7: Copy Constructor Contents
   *
   * Tests if the original wordset and copy wordset have the same elements 
   * after using the copy constructor (and thus the assignment operator)
   *
   */
  {
    cs3505::wordset  our_set_of_words(1000);  // Our set class, with a hashtable of 1000 slots.    

    ifstream in("Yankee.txt");

    // Loop for reading the file.  Note that it is controlled
    //   from within the loop (see the 'break').
    
    while (true)
    {
      // Read a word (don't worry about punctuation)
      
      string word;
      in >> word;

      // If the read failed, we're probably at end of file
      //   (or else the disk went bad).  Exit the loop.
      
      if (in.fail())
        break;

      // Word successfully read.  Add it to wordset.
      our_set_of_words.add(word);            
    }

    in.close();

    // Copy original wordset into new wordset
    cs3505::wordset  copy_set_of_words(our_set_of_words); // A copy of our set of words

    // Make an array of strings to hold copy elements
    string *original_words = new string[our_set_of_words.size()];

    // Get elements in our word set
    our_set_of_words.get_elements(original_words, our_set_of_words.size());

    for(int i = 0; i < our_set_of_words.size(); i++)
      if(!(copy_set_of_words.contains(original_words[i])))
      {
        cout << "ERROR: The copied wordset does not contain at least one word from the original wordset" << endl;
        tests_passed = false;
      }

    delete [] original_words;
  }  

  /* Test 8: Remove Size
   *
   * Tests when we add all theelements from Yankee.txt then remove all the elements 
   * from Yankee.txt that the resulting size should equal zero.
   *
   */
  {
    cs3505::wordset  our_set_of_words(1000);  // Our set class, with a hashtable of 1000 slots.    

    // Open the file stream for reading.  (We'll be able to use it just like
    //   the keyboard stream 'cin'.)

    ifstream in("Yankee.txt");

    // Loop for reading the file.  Note that it is controlled
    //   from within the loop (see the 'break').
    
    while (true)
    {
      // Read a word (don't worry about punctuation)
      
      string word;
      in >> word;

      // If the read failed, we're probably at end of file
      //   (or else the disk went bad).  Exit the loop.
      
      if (in.fail())
        break;

      // Word successfully read.  Add it to wordset.
      our_set_of_words.add(word);            
    }

    // Close the file.

    in.close();

    // Open the file stream for reading.  (We'll be able to use it just like
    //   the keyboard stream 'cin'.)

    ifstream inn("Yankee.txt");

    // Loop for reading the file.  Note that it is controlled
    //   from within the loop (see the 'break').
    
    while (true)
    {
      // Read a word (don't worry about punctuation)
      
      string word;
      inn >> word;

      // If the read failed, we're probably at end of file
      //   (or else the disk went bad).  Exit the loop.
      
      if (inn.fail())
        break;

      // Word successfully read.  Remove it from wordset.
      our_set_of_words.remove(word);     
    }

    // Close the file.
    inn.close();

    if(our_set_of_words.size() != 0)
    {
      cout << "ERROR: The remove method failed to remove the correct number of elements, size should have equaled zero but did not" << endl;
      tests_passed = false;
    }
  }
  

  /* Test 9: Remove Contents
   *
   * Tests if our regular set and our wordset have the same contents
   * after adding and then removing different string elements. 
   *
   */
  {
    set<string>      stl_set_of_words;  // The built-in set class - no constructor parameters.

    cs3505::wordset  our_set_of_words(1000);  // Our set class, with a hashtable of 1000 slots.    

    // -------------- Add stuff ---------------- //

    stl_set_of_words.insert("Hello");
    our_set_of_words.add("Hello");            
    
    for (set<string>::iterator it = stl_set_of_words.begin(); it != stl_set_of_words.end(); it++)
    {
      string s = *it;
      if(!(our_set_of_words.contains(s)))
      {
        cout << "ERROR: Wordset failed to add the same elements as the regular set." << endl;
        tests_passed = false;
      }
    }

    stl_set_of_words.insert("Goodbye");
    our_set_of_words.add("Goodbye");            
    
    for (set<string>::iterator it = stl_set_of_words.begin(); it != stl_set_of_words.end(); it++)
    {
      string s = *it;
      if(!(our_set_of_words.contains(s)))
      {
        cout << "ERROR: Wordset failed to add the same elements as the regular set." << endl;
        tests_passed = false;
      }
    }

    stl_set_of_words.insert("So Long");
    our_set_of_words.add("So Long");            
    
    for (set<string>::iterator it = stl_set_of_words.begin(); it != stl_set_of_words.end(); it++)
    {
      string s = *it;
      if(!(our_set_of_words.contains(s)))
      {
        cout << "ERROR: Wordset failed to add the same elements as the regular set." << endl;
        tests_passed = false;
      }
    }

    stl_set_of_words.insert("Farewell");
    our_set_of_words.add("Farewell");            
    
    for (set<string>::iterator it = stl_set_of_words.begin(); it != stl_set_of_words.end(); it++)
    {
      string s = *it;
      if(!(our_set_of_words.contains(s)))
      {
        cout << "ERROR: Wordset failed to add the same elements as the regular set." << endl;
        tests_passed = false;
      }
    }

    // -------------- Remove stuff ---------------- //

    stl_set_of_words.erase("Hello");
    our_set_of_words.remove("Hello"); 

    if(our_set_of_words.contains("Hello"))
    {
      cout << "ERROR: Wordset failed to remove the correct element." << endl;
      tests_passed = false;
    }
    
    for (set<string>::iterator it = stl_set_of_words.begin(); it != stl_set_of_words.end(); it++)
    {
      string s = *it;
      if(!(our_set_of_words.contains(s)))
      {
        cout << "ERROR: Wordset and regular set do not contain the same elements after removing, but they should;" << endl;
        tests_passed = false;
      }
    }

    stl_set_of_words.erase("Goodbye");
    our_set_of_words.remove("Goodbye");            
    
    if(our_set_of_words.contains("Goodbye"))
    {
      cout << "ERROR: Wordset failed to remove the correct element." << endl;
      tests_passed = false;
    }

    for (set<string>::iterator it = stl_set_of_words.begin(); it != stl_set_of_words.end(); it++)
    {
      string s = *it;
      if(!(our_set_of_words.contains(s)))
      {
        cout << "ERROR: Wordset and regular set do not contain the same elements after removing, but they should;" << endl;
        tests_passed = false;
      }
    }

    stl_set_of_words.erase("So Long");
    our_set_of_words.remove("So Long");            
    
    if(our_set_of_words.contains("So Long"))
    {
      cout << "ERROR: Wordset failed to remove the correct element." << endl;
      tests_passed = false;
    }

    for (set<string>::iterator it = stl_set_of_words.begin(); it != stl_set_of_words.end(); it++)
    {
      string s = *it;
      if(!(our_set_of_words.contains(s)))
      {
        cout << "ERROR: Wordset and regular set do not contain the same elements after removing, but they should;" << endl;
        tests_passed = false;
      }
    }

    stl_set_of_words.erase("Farewell");
    our_set_of_words.remove("Farewell");            
    
    if(our_set_of_words.contains("Farewell"))
    {
      cout << "ERROR: Wordset failed to remove the correct element." << endl;
      tests_passed = false;
    }

    for (set<string>::iterator it = stl_set_of_words.begin(); it != stl_set_of_words.end(); it++)
    {
      string s = *it;
      if(!(our_set_of_words.contains(s)))
      {
        cout << "ERROR: Wordset and regular set do not contain the same elements after removing, but they should;" << endl;
        tests_passed = false;
      }
    }
  }

  /* Test 10: Assignment Size
   *
   * Tests if our copy wordset has the same size as our original wordset
   * after using the = assignment operator 
   *
   */
  {
    cs3505::wordset  original_words(1000);  // Our set class, with a hashtable of 1000 slots.    

    original_words.add("Hello");
    original_words.add("Goodbye");
    original_words.add("So Long");
    original_words.add("Farewell");

    cs3505::wordset  copy_words = original_words; // A copy of our set of words

    if(copy_words.size() != 4)
    {
      cout << "ERROR: The copied wordset does not have the same size as original wordset after using = assignment." << endl;
      tests_passed = false;
    }
  }

  /* Test 11: Assignment Contents
   *
   * Tests if our copy wordset has the same contents as our original wordset
   * after using the = assignment operator 
   *
   */
  {
    cs3505::wordset  original_words(1000);  // Our set class, with a hashtable of 1000 slots.    

    original_words.add("Hello");
    original_words.add("Goodbye");
    original_words.add("So Long");
    original_words.add("Farewell");

    cs3505::wordset  copy_words = original_words; // A copy of our set of words

    if(!(copy_words.contains("Hello")))
    {
      cout << "ERROR: The copied wordset does not have the same contents as original wordset after using = assignment." << endl;
      tests_passed = false;
    }

    if(!(copy_words.contains("Goodbye")))
    {
      cout << "ERROR: The copied wordset does not have the same contents as original wordset after using = assignment." << endl;
      tests_passed = false;
    }

    if(!(copy_words.contains("So Long")))      
    {
      cout << "ERROR: The copied wordset does not have the same contents as original wordset after using = assignment." << endl;
      tests_passed = false;
    }

    if(!(copy_words.contains("Farewell")))
    {
      cout << "ERROR: The copied wordset does not have the same contents as original wordset after using = assignment." << endl;
      tests_passed = false;
    }
  }

  /* Test 12: Remove Not Included
   *
   * Tests if the remove function does anything when we try to remove an element not in the wordset
   *
   */
  {
    cs3505::wordset  our_set_of_words(1000);  // Our set class, with a hashtable of 1000 slots.    

    our_set_of_words.add("Hello");
    our_set_of_words.add("Goodbye");

    // Try to remove a word not in the set
    our_set_of_words.remove("Farewell");    

    if(our_set_of_words.size() != 2)
    {
      cout << "ERROR: Removing a word not in the wordset changed the size, but should have done nothing." << endl;
      tests_passed = false;
    }

    if(!(our_set_of_words.contains("Hello")) || !(our_set_of_words.contains("Goodbye")))
    {
      cout << "ERROR: Removing a word not in the wordset removed the wrong word." << endl;
      tests_passed = false;
    }
  }

  /* Test 13: Remove When Empty
   *
   * Tests what happens if we try to remove a word when the wordset is empty
   *
   */
  {
    cs3505::wordset  our_set_of_words(1000);  // Our set class, with a hashtable of 1000 slots.    

    // Try to remove a word not in the set
    our_set_of_words.remove("Farewell");    

    if(our_set_of_words.size() != 0)
    {
      cout << "ERROR: Removing a word when the wordset is empty caused the size to erroneously change." << endl;
      tests_passed = false;
    }
  }

  /* Test 14: Copy Constructor Empty
   *
   * Tests the copy constructor when we copy an empty wordset
   *
   */
  {
    cs3505::wordset  our_set_of_words(1000);  // Our set class, with a hashtable of 1000 slots.    

    // Copy original wordset into new wordset
    cs3505::wordset  copy_set_of_words(our_set_of_words); // A copy of our set of words

    if(copy_set_of_words.size() != our_set_of_words.size())
    {
      cout << "ERROR: The sizes of the copied wordset and original wordset are not the same when original in empty;" << endl;
      tests_passed = false;
    }
  }

  /************************** End My Tests **************************/

  if(tests_passed)
    cout << "Tests passed\n" << endl;
  else 
    cout << "Tests failed\n" << endl;

  // Now that the objects have been destroyed, I will simply call my auditing
  // code to print out how many times constructors have been called, and
  // how many times destructors have been called.  They should exactly match.
  // If not, we have a memory problem.

  cout << "Class cs3505::wordset:" << endl;
  cout << "    Objects created:  " << cs3505::wordset::constructor_count() << endl;
  cout << "    Objects deleted:  " << cs3505::wordset::destructor_count() << endl;
  cout << endl;

  cout << "Class cs3505::node:" << endl;
  cout << "    Objects created:  " << cs3505::node::constructor_count() << endl;
  cout << "    Objects deleted:  " << cs3505::node::destructor_count() << endl;
  cout << endl;

  if(tests_passed)
    cout << "Tests passed" << endl;
  else 
    cout << "Tests failed" << endl;

  // Now we're really done.  End main.
  
  return 0;
}
