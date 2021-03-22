#include <iostream>
#include <list>
#include <cstring>
#include "hashtable.hpp"
using namespace std;



bool HashTable::isEmpty() const{
    int sum{};
    for(int i{}; i < hashGroups;i++){
        sum+= table[i].size(); // Iterate through each hasgroup and see its size
    }
    if (!sum){
        return true;
    }
    return false;
    
}

int HashTable::hashFunction(int key){
    return key % hashGroups; // key : 905 func should return 5. this represents the 6th list in the table
}

void HashTable::insertItem(int key, string value){
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto begIter = begin(cell);
    bool keyExists = false; //Assume key doesnt exist intially. 
    for(;begIter != end(cell); begIter++){
        if(begIter->first == key){
            keyExists = true;
            begIter->second = value; // Key exists and has been replaced
            break;
        }
    }
    if(!keyExists){
        cell.emplace_back(key,value); // cell is the list we are interested in
    }
    return;
}

void HashTable::removeItem(int key){
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto begIter = begin(cell);
    bool keyExists = false; //Assume key doesnt exist intially. 
    for(;begIter != end(cell); begIter++){
        if(begIter->first == key){
            keyExists = true;
            begIter = cell.erase(begIter);
            //begIter->second = value; // Key exists and has been replaced
            break;
        }
    }
    if(!keyExists){
        //item not found 
        cout<<"No item found to be removed"<<endl;
    }
    return;
}

string HashTable::searchTable(int key) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto begIter = begin(cell);
    return begIter->second;
}

void HashTable::printTable(){
    for(int i{}; i < hashGroups;i++)
    {
        if(table[i].size() == 0) continue;
        auto begiter = table[i].begin();
        for (;begiter != table[i].end();begiter++)
        {
            cout<<"Key: "<<begiter->first<< " Value: "<<begiter->second<<endl;
        }
        
    }
    return;
}
int HashTable::getHashGroups() {
    return hashGroups;
}