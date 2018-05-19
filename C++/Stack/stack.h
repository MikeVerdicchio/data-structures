#ifndef STACK_H
#define STACK_H

#include "stack_node.h"

class Stack
{
  public:
    Stack();
    ~Stack();
    void push(int x);
    void pop();
    int top();
    bool empty() const;

  private:
    StackNode *head;
    StackNode *tail;
    int count;
};

#endif