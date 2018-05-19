#include <iostream>
#include "huffman_tree_node.h"
#include "huffman_tree.h"
#include "heap.h"

Heap::Heap(int max) : myHeap(max + 1), heap_size(0)
{
}

Heap::~Heap()
{
    makeEmpty();
}

bool Heap::isEmpty()
{
    return (heap_size == 0);
}

void Heap::makeEmpty()
{
    while (!isEmpty())
    {
        deleteMin();
    }
}

void Heap::insert(HuffmanTree *temp)
{
    if (heap_size == myHeap.size() - 1)
    {
        myHeap.resize((heap_size + 1) * 2);
    }
    heap_size += 1;
    int hole = heap_size;
    while ((hole > 1) && (*temp < (*(myHeap[hole / 2]))))
    {
        myHeap[hole] = myHeap[hole / 2];
        hole /= 2;
    }
    myHeap[hole] = temp;
}

HuffmanTree *Heap::findMin()
{
    if (isEmpty())
    {
        throw "findMin() called on empty heap";
    }
    return myHeap[1];
}

HuffmanTree *Heap::deleteMin()
{
    if (isEmpty())
    {
        throw "deleteMin() called on empty heap";
    }
    HuffmanTree *ret = myHeap[1];
    myHeap[1] = myHeap[heap_size--];
    percolateDown(1);
    return ret;
}

void Heap::percolateDown(int hole)
{
    HuffmanTree *x = myHeap[hole];
    int child;

    while (hole * 2 <= heap_size)
    {
        child = hole * 2;
        if ((child != heap_size) && (*(myHeap[child + 1]) < *(myHeap[child])))
        {
            child++;
        }

        if (*x > *(myHeap[child]))
        {
            myHeap[hole] = myHeap[child];
        }
        else
        {
            break;
        }
        hole = child;
    }

    myHeap[hole] = x;
}