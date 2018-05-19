#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include "huffman_tree.h"

class Heap
{
  public:
    Heap(int max);
    ~Heap();

    bool isEmpty();
    void makeEmpty();

    void insert(HuffmanTree *temp);
    HuffmanTree *findMin();
    HuffmanTree *deleteMin();

  private:
    int heap_size;
    std::vector<HuffmanTree *> myHeap;
    void percolateDown(int hole);
};

#endif