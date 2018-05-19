#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <list>

class HashTable
{
  public:
    HashTable(int size);
    ~HashTable();
    int capacity;
    int largestWord;
    bool insert(const std::string &string);
    bool contains(const std::string &string) const;

  private:
    std::vector< std::list<std::string> > *buckets;
    int hash(const std::string &string) const;
    int nextPrime(unsigned int n);
    bool checkPrime(unsigned int p);
};

#endif