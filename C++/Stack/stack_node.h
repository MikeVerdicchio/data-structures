#ifndef STACK_NODE_H
#define STACK_NODE_H

class StackNode
{
  public:
    StackNode();

  private:
    int value;
    StackNode *next;
    StackNode *previous;
    friend class Stack;
};

#endif