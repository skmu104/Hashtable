//
// Created by suraj on 19/03/2021.
//

#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include <iostream>
#include <list>
#include <cstring>
using namespace std;

class HashTable{
private:
    static const int hashGroups = 10;
    list<pair<int,string>> table[hashGroups];
public:
    bool isEmpty() const;
    int hashFunction(int key);
    void insertItem(int key, string value);
    void removeItem(int key);
    string searchTable(int key);
    void printTable();
    int getHashGroups();
};



#endif //C__DEV_HASHTABLE_HPP
