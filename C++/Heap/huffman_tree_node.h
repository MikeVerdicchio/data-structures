#ifndef HUFFMAN_TREE_NODE_H
#define HUFFMAN_TREE_NODE_H

class HuffmanTreeNode
{
  public:
    HuffmanTreeNode *left;
    HuffmanTreeNode *right;
    char character;

    HuffmanTreeNode(char c, HuffmanTreeNode *l, HuffmanTreeNode *r)
    {
        character = c;
        left = l;
        right = r;
    }
};

#endif