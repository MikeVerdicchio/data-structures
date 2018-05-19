#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

#include "huffman_tree_node.h"
#include <map>
#include <string>

class HuffmanTree
{
  public:
    HuffmanTreeNode *root;
    int frequency;
    std::map<char, std::string> codeMap;

    HuffmanTree();
    HuffmanTree(char c, int f);
    ~HuffmanTree();
    void printCode();
    void insertCode(char c, int f);

    bool operator<(HuffmanTree &temp) const
    {
        return (frequency < temp.frequency);
    }

    bool operator>(HuffmanTree &temp) const
    {
        return (frequency > temp.frequency);
    }

  private:
    void printCode(HuffmanTreeNode *root, std::string code);
};

#endif