#include "list.h"

List::List()
{
    int count = 0;

    head = new ListNode();
    head->next = tail;
    head->previous = NULL;

    tail = new ListNode();
    tail->previous = head;
    tail->next = NULL;
}

// Copy Constructor
List::List(const List &source)
{
    head = new ListNode;
    tail = new ListNode;
    head->next = tail;
    tail->previous = head;
    count = 0;
    ListItr iter(source.head->next);

    // deep copy of the list
    while (!iter.isPastEnd())
    {
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

List::~List()
{
    makeEmpty();
    delete head;
    delete tail;
}

// Equals operator
List &List::operator=(const List &source)
{
    if (this == &source)
    {
        return *this;
    }
    else
    {
        makeEmpty();
        ListItr iter(source.head->next);
        while (!iter.isPastEnd())
        {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

bool List::isEmpty() const
{
    if ((head->next == tail) && (tail->previous == head))
        return true;
    else
        return false;
}

void List::makeEmpty()
{
    ListItr iterator(head->next);
    while (iterator.isPastEnd() == false)
    {
        ListNode *deleteNode = iterator.current;
        delete deleteNode;
    }

    count = 0;
    head->next = tail;
    tail->previous = head;
}

ListItr List::first()
{
    ListItr firstOne(head->next);
    return firstOne;
}

ListItr List::last()
{
    ListItr lastOne(tail->previous);
    return lastOne;
}

void List::insertAfter(int x, ListItr position)
{
    ListNode *node = new ListNode();
    node->value = x;
    node->previous = position.current;
    node->next = position.current->next;
    position.current->next = node;
    node->next->previous = node;
    count++;
}

void List::insertBefore(int x, ListItr position)
{
    ListNode *node = new ListNode();
    node->value = x;
    node->next = position.current;
    node->previous = position.current->previous;
    position.current->previous = node;
    node->previous->next = node;
    count++;
}

void List::insertAtTail(int x)
{
    ListItr iterator(tail);
    insertBefore(x, iterator);
}

void List::remove(int x)
{
    ListItr iterator(head->next);
    while (iterator.isPastEnd() == false)
    {
        if (iterator.current->value == x)
        {
            iterator.current->next->previous = iterator.current->previous;
            iterator.current->previous->next = iterator.current->next;
            count--;
            delete iterator.current;
            return;
        }
        else
        {
            iterator.moveForward();
        }
    }
}

ListItr List::find(int x)
{
    ListItr iterator(head->next);
    while (iterator.isPastEnd() == false)
    {
        if (iterator.current->value == x)
        {
            return iterator;
        }
        else
        {
            iterator.moveForward();
        }
    }
    iterator.current = tail;
    return iterator;
}

int List::size() const
{
    return count;
}

void printList(List &source, bool direction)
{
    if (direction == true)
    {
        ListItr iterator = source.first();
        for (int i = 0; i < source.size(); i++)
        {
            std::cout << iterator.retrieve() << std::endl;
            iterator.moveForward();
        }
    }
    else
    {
        ListItr iterator = source.last();
        for (int i = 0; i < source.size(); i++)
        {
            std::cout << iterator.retrieve() << std::endl;
            iterator.moveBackward();
        }
    }
}