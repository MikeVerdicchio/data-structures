#ifndef LIST_NODE_H
#define LIST_NODE_H

class ListNode
{
  public:
    ListNode();

  private:
    int value;
    ListNode *next, *previous;

    friend class List;
    friend class ListItr;
};

#endif
