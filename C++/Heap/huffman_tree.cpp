#include "huffman_tree.h"
#include "huffman_tree_node.h"
#include <map>
#include <iostream>
#include <string>

typedef pair<char, string> myPair;

HuffmanTree::HuffmanTree()
{
    root = NULL;
    frequency = 0;
}

HuffmanTree::HuffmanTree(char c, int f)
{
    HuffmanTreeNode *node = new HuffmanTreeNode(c, NULL, NULL);
    root = node;
    frequency = f;
}

HuffmanTree::~HuffmanTree()
{
    delete root;
}

void HuffmanTree::printCode()
{
    printCode(root, "");
}

void HuffmanTree::printCode(HuffmanTreeNode *root, string code)
{
    if ((root->left == NULL) && (root->right == NULL))
    {
        cout << (root->character) << " " << code << endl;
        codeMap.insert(myPair(root->character, code));
    }
    if (root->left != NULL)
    {
        printCode(root->left, code + "0");
    }
    if (root->right != NULL)
    {
        printCode(root->right, code + "1");
    }
}

void HuffmanTree::insertCode(char c, int f)
{
    HuffmanTreeNode *node;
    node = root;
    root = new HuffmanTreeNode('\0', NULL, NULL);
    root->left = new HuffmanTreeNode(c, NULL, NULL);
    root->right = node;
    frequency += f;
}