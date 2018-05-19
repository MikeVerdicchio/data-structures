#include <string>
#include <list>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include "hash_table.h"

HashTable::HashTable(int size)
{
    buckets = new std::vector<std::list<std::string>>();
    size = size / 0.75; // Load factor

    if (!checkPrime(size))
    {
        size = nextPrime(size);
    }

    capacity = size;
    buckets->resize(size);
    largestWord = 0;

    for (int i = 0; i < size; i++)
    {
        std::list<std::string> temp;
        buckets->push_back(temp);
    }
}

HashTable::~HashTable()
{
    delete buckets;
}

bool HashTable::insert(const std::string &str)
{
    if (!contains(str))
    {
        std::list<std::string> &l = (buckets->at(hash(str)));
        l.push_back(str);

        if (str.length() > largestWord)
        {
            largestWord = str.length();
        }
        return true;
    }
    return false;
}

bool HashTable::contains(const std::string &str) const
{
    std::list<std::string> &l = (buckets->at(hash(str)));
    return (find(l.begin(), l.end(), str) != l.end());
}

int HashTable::hash(const std::string &string) const
{
    int hashValue = 0;
    int length = string.length();

    for (int i = 0; i < length; i++)
    {
        hashValue += (string[i] * 43) % 512;
    }
    return hashValue % (capacity);
}

// COPIED FROM PROFESSOR BLOOMFIELD'S primenumber.cpp FILE
int HashTable::nextPrime(unsigned int n)
{
    while (!checkPrime(++n))
        ;
    return n;
}

// COPIED FROM PROFESSOR BLOOMFIELD'S primenumber.cpp FILE
bool HashTable::checkPrime(unsigned int p)
{
    if (p <= 1) // 0 and 1 are not primes; the are both special cases
    {
        return false;
    }

    if (p == 2) // 2 is prime
    {
        return true;
    }

    if (p % 2 == 0) // even numbers other than 2 are not prime
    {
        return false;
    }

    for (int i = 3; i * i <= p; i += 2) // only go up to the sqrt of p
    {
        if (p % i == 0)
        {
            return false;
        }
    }

    return true;
}