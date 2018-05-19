#include <iostream>
#include "stack.h"

Stack::Stack()
{
    count = 0;

    head = new StackNode();
    head->next = NULL;
    head->previous = tail;

    tail = new StackNode();
    tail->previous = NULL;
    tail->next = head;
}

Stack::~Stack()
{
    delete head;
    delete tail;
}

void Stack::push(int x)
{
    StackNode *node = new StackNode();
    node->value = x;
    count++;

    node->previous = head->previous;
    node->next = head;
    head->previous = node;
}

void Stack::pop()
{
    if (!empty())
    {
        head->previous = head->previous->previous;
        count--;
    }
    else
    {
        std::cout << "Cannot pop. The stack is already empty." << std::endl;
    }
}

int Stack::top()
{
    if (!empty())
    {
        return head->previous->value;
    }
    else
    {
        std::cout << "Cannot get top. The stack is empty." << std::endl;
        return -1;
    }
}

bool Stack::empty() const
{
    return (count == 0);
}