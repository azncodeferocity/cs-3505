/* Author: Basil Vetas
 * Date: January 26, 2015
 * Course: CS 3505
 * Assignment: 3
 * 
 * A 'word set' is defined as a set of strings stored
 * in a hashtable that uses chaining to resolve collisions.
 *
 * Peter Jensen
 * January 22, 2015
 */

#include <iostream>
#include <string>
#include "wordset.h"
#include "node.h"

namespace cs3505
{
  /*******************************************************
   * wordset member function definitions
   ***************************************************** */

  
  /** Constructor:  The parameter indicates the
    *   size of the hashtable that should be used
    *   to keep this set.
    */
  wordset::wordset(int capacity)
  {
    // Do not change or remove the following line.
    //   It must execute for our auditing to be correct.

    wordset::constructor_calls++;

    // Normal constructor tasks below.
    
    this->capacity = capacity;
    this->count = 0;
    this->table = new node*[capacity];  // Create table (array of node pointers)

    // Make sure the table is clear.  (Not normally cleared on new.)
    
    for (int i = 0; i < capacity; i++)
      table[i] = NULL;
  }

  
  /** Copy constructor:  Initialize this set
    *   to contain exactly the same elements as
    *   another set.
    */
  wordset::wordset(const wordset & other)
  {
    // Do not change or remove the following line.
    //   It must execute for our auditing to be correct.

    wordset::constructor_calls++;

    // Normal constructor tasks below.

    // Initialize this object to appear cleaned.
    
    this->capacity = 0;
    this->count = 0;
    this->table = NULL;

    // Use our overloaded assignment operator to do the work
    //   of copying the parameter's elements into this object.
    
    *this = other;
  }

  
  /** Destructor:  release any memory allocated
    *   for this object.
    */
  wordset::~wordset()
  {
    // Do not change or remove the following line.
    //   It must execute for our auditing to be correct.

    wordset::destructor_calls++;

    // Normal destructor tasks below.
    
    clean();  // This does all the work.
  }

  
  /** Adds the specified element to this set.  If the element
    *   is already in this set, no action is taken.
    */
  void wordset::add (std::string element)
  {
    // This has been revised slightly from class.  If the
    //   element is not in the linked list (at the correct
    //   table position), I add it to the END of the linked
    //   list.  (I do this because you will use similar
    //   variables and looping in your remove method.)
    
    // Locate the table entry that would contain it.    
    int index = hash(element);
    
    // Each table entry is the head of a linked list.
    //   Follow it, looking for the element.  Also,
    //   keep track of the last node visited.

    node *current = table[index], *last = NULL;
    
    while (current != NULL)
    {
      if (current->data == element)  // Does a char-by-char comparison
        return;  // Found it - do nothing - it's already in the set.
      last = current;           // Keep track of current as last visited node
      current = current->next;  // Advance to next node
    }

    // Element does not exist in the set.  Create a
    //   node object to contain it.  (New returns
    //   a pointer to it.)
    
    current = new node(element);

    // Add the node to our linked list.  Either
    //   add it to the end of the existing list,
    //   or start a new list.

    if (last == NULL)  // No existing list
      table[index] = current;  // The node becomes the head of a list
    else
      last->next = current;  // Add to end of existing list.

    // Keep track of the number of elements successfully added.
    
    count++;
  }

  
  /** Removes the specified element from this set.  If the
    *   element is not in the set, no action is taken.
    */
  void wordset::remove (std::string element)
  {
    // Requirement:  When an element is removed, its
    //   enclosing node must be unlinked from that
    //   linked list, and then the node must be deleted
    //   to free up its memory.  The linked list and/or
    //   table must be appropriately updated.
    
    /*** To be completed by students. ***/

    // Locate the table entry that would contain it.    
    int index = hash(element);

    // Each table entry is the head of a linked list.
    //   Follow it, looking for the element. Also,
    //   keep track of the last node visited.

    node *current = table[index], *last = NULL;    

    while (current != NULL)
    {
      // If we find it in the linked list
      if (current->data == element)  // Does a char-by-char comparison      
      {
        // Keep a copy of the object pointed to by next
        node *temp_next = current->next;  

        // Delete the node.  All its storage should be
        //   considered illegal.  (Afterwards, we cannot access
        //   anything inside of it, not even .next)
        delete current;

        // If the last node is null, make the next node (after current) the new head of the list
        if(last == NULL)
          table[index] = temp_next;
        else // otherwise, make the last->next point to the next node (after current)
          last->next = temp_next; 

        count--;  // decrement count

        return;  // Return after removing since there are no duplicates
      }

      last = current;           // Keep track of current as last visited node
      current = current->next;  // Advance to next node
    }
  }

  /** Returns true if the specified element in in this set,
    *   false otherwise.
    */
  bool wordset::contains (std::string element) const
  {
    // Locate the table entry that would contain it.    
    int index = hash(element);

    // Each table entry is the head of a linked list.
    //   Follow it, looking for the element.

    node *current = table[index];  // Get the head of the list

    while (current != NULL)
    {
      if (current->data == element)  // Does a char-by-char comparison
        return true;  // Found it.
      
      current = current->next;  // Advance to next node
    }
    
    return false;  // Did not find it.
  }

  
  /** Returns a count of the number of elements
    *   in this set.
    */
  int wordset::size () const
  {
    return count;
  }

  
  /*** Assignment operator ***/
  
  /** This function overloads the assignment operator.  It
    *   clears out this set, builds an empty table, and copies
    *   the entries from the right hand side (rhs) set into
    *   this set.
    */
  wordset & wordset::operator= (const wordset & rhs)
  {
    // If we are assigning this object to this object,
    //   do nothing.  (This is important!)

    if (this == &rhs)  // Compare addresses (not object contents)
      return *this;  // Do nothing if identical

    // Wipe away anything that is stored in this object.
    
    clean();
    
    // Create a new set (new table) and populate it with the entries
    //   from the set in rhs.  Use the capacity from rhs.  Hint:
    //   see the first constructor above (but you cannot call it).
    
    // Requirement:  Do not permanently point to arrays or nodes in rhs.  
    //   When rhs is destroyed, it will delete its array and nodes, 
    //   and we cannot count on their existence.  Instead, you will
    //   create a new array for this object, traverse rhs,
    //   and add one entry to this set for every entry in rhs.

    /*** Student work goes here ***/

    this->capacity = rhs.capacity;
    this->count = 0;
    this->table = new node*[capacity];  // Create table (array of node pointers)

    // Clear table 
    for (int i = 0; i < capacity; i++)
      table[i] = NULL;

    // Traverse the rhs and copy into this->table (rhs and this have same capacity)
    for (int i = 0; i < capacity; i++)
    {
      // Get the first node in the linked list at table[i]
      node *rhs_current = rhs.table[i];

      // Traverse each linked list, adding to this->table
      while (rhs_current != NULL)
      {
        // Add each data element from rhs to our table
        add(rhs_current->data);        
        
        rhs_current = rhs_current->next;  // Advance to next node of rhs      
      }
    }

    // Done with assignment operator.
    return *this;
  }

   /** This function populates an array of strings with elements from the set.
    * The caller passes an array (by pointer) and a count 'n' to the function.
    * The function copies n unique elements from the set into
    * the array.  (Order does not matter.)  If 'n' is smaller
    * than the number of elements in the set, only 'n' elements are
    * copied into the array in positions [0..n-1].  If 'n' is larger than the number
    * of elements in the set, all the elements in the set are
    * copied into the first positions of the array, and excess positions
    * in the array remain unchanged.
    *
    * It is assumed that the array reference is valid and that n is non-negative.
    */
    void wordset::get_elements(std::string *array, int n) const
    {
      int copied = 0; // counter for the number of elements we've copied

      int elements_needed = 0;

      // check how many elements we want to add into the array
      if(n <= count)
        elements_needed = n;
      else
        elements_needed = count;

      // Traverse the table 
      for (int i = 0; i < capacity; i++)
      {
        // Get the first node in the linked list at table[i]
        node *current = table[i];

        // Traverse each linked list at current
        while (current != NULL)
        {
          if(copied < elements_needed) // If we still need more elements, copy one over
          {
            array[copied] = current->data;
            copied++;
          }
          else  // If we have copied over all the elements then just return
            return;

          current = current->next;  // Advance to next node of this list      
        }
      }
    }

  /****************** Private helper functions ******************/




  /** Computes a table index for a given string.
    *   If two strings have the same contents, their
    *   hash code (table index) will be identical.
    * The hash code is guaranteed to be in the
    *   range [0..capacity).
    */  
  int wordset::hash (std::string s) const
  {
    // A well-known algorithm for computing string hash codes.
    // Students should not change this algorithm in any way.
    
    long long hash = 0;
    for (int i = 0; i < s.length(); i++)
      hash = ((hash * 1117) + s[i]) % capacity;

    return static_cast<int>(hash);
  }


  /** Releases any memory that was allocated by
    *   this object.  This effectively destroys the
    *   set, so it should only be called if this object
    *   is destructing, or is being assigned.
    */
  void wordset::clean ()
  {
    // If the object is already clean, do nothing.
    //   (Our representation for a clean object is that
    //   the table pointer is NULL).
    
    if (table == NULL)  
      return;

    // Delete all the nodes in the table.

    for (int i = 0; i < capacity; i++)
    {
      // Each entry in the table is the head of a linked list.
      // Follow the head to each node and delete the nodes.

      node *current = table[i];

      while (current != NULL)
      {
        // Keep a copy of the next pointer.

        node *temp_next = current->next;

        // Delete the node.  All its storage should be
        //   considered illegal.  (Afterwards, we cannot access
        //   anything inside of it, not even .next)

        delete current;

        // Advance to the next node.

        current = temp_next;
      }      
    }

    // The nodes are all deleted.  Just delete the table.

    delete [] table;  // Notice the syntax for deleting an array.
    
    // We're done freeing up memory, but we should set
    //   our pointer to the array to NULL to indicate to
    //   ourself that it has been deleted.  (This also prevents
    //   us from accidentally using it.)

    table = NULL;

    // Done cleaning up.
  }

  
  /*******************************************************
   * wordset static definitions:
   *
   *     These are for debugging purposes only.  They help 
   * the programmer audit their memory usage.
   *
   *     Do not change anything below this point.
   ***************************************************** */

  // We have not covered static class members.  Since static
  // variables are not in objects, we need to define storage
  // for them.  These variables are -here-, not in any object.
  // (This is the only copy of these variables that will exist.)
  
  long long wordset::constructor_calls = 0;
  long long wordset::destructor_calls = 0;


  /** Returns the number of times any wordset
    *   constructor has been called.
    */
  long long wordset::constructor_count ()
  {
    return wordset::constructor_calls;
  }

  
  /** Returns the number of times the wordset
    *   destructor has been called.
    */
  long long wordset::destructor_count ()
  {
    return wordset::destructor_calls;
  }

}
