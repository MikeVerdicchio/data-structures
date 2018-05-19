#ifndef LIST_ITERATOR_H
#define LIST_ITERATOR_H

#include "list_node.h"

class ListItr
{
  public:
    ListItr();                    // Constructor
    ListItr(ListNode *theNode);   // One parameter constructor
    bool isPastEnd() const;       // Returns true if past end position in list, else false
    bool isPastBeginning() const; // Returns true if past first position in list, else false
    void moveForward();           // Advances current to next position in list (unless already past end of list)
    void moveBackward();          // Moves current back to previous position in list (unless already past beginning of list)
    int retrieve() const;         // Returns item in current position

  private:
    ListNode *current; // Holds the position in the list
    friend class List; // List class needs access to current ListNode's private data members
};

#endif