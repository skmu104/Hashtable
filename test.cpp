//
// Created by suraj on 16/03/2021.
//
// TODO create make file

#include <iostream>
#include "string.h"
#include <list>
#include <vector>
#include "hashtable.hpp"


using namespace std;
#define ASSERT(condition)                                                         \
    if ((condition) == false) {                                                   \
        cout << "FAILURE @ : " << __FILE__ << ":" << __LINE__ << "\n"                \
             << "\tExpression '" << #condition << "' evaluated to false" << endl; \
        return false;                                                           \
    }


// Definitions of test cases
bool checkEmpty(){ // Checks to see if table empty or not
    HashTable h;

    ASSERT(h.isEmpty() == true);
    return true;
}

bool checkInsert(){ // Checks to see if hashtable insert functionality is working
    HashTable h;
    ASSERT(h.isEmpty() == true);
    h.insertItem(105, "person1");
    h.insertItem(233, "person2");
    h.insertItem(505, "person3");
    ASSERT(h.isEmpty() == false);
    return true;
}

bool checkRemove(){ // Checks to see if hashtable remove functionality is working
    HashTable h;
    ASSERT(h.isEmpty() == true);
    h.insertItem(105, "person1");
    h.removeItem(105);
    ASSERT(h.isEmpty() == true);
    return true;
}

bool checkSearch(){ // checks to see if hashtable search functionality is working
    HashTable h;
    ASSERT(h.isEmpty() == true);
    h.insertItem(505, "person1");
    h.insertItem(102, "person2");
    ASSERT(h.isEmpty() == false);
    ASSERT(h.searchTable(102) == "person1");
    ASSERT(h.searchTable(102) == "person2");
    return true;
}

vector<bool> runtTests(){ // Stores the results of tests into a list
    vector<bool> results; // Initialise vector to store results
    // Run chosen tests
    results.push_back(checkEmpty());
    results.push_back(checkInsert());
    results.push_back(checkRemove());
    results.push_back(checkSearch());
    return results;
}

int main(){

    vector<bool> pTest = runtTests();
    for (int i = 0; i < pTest.size(); i++) {
        if (pTest[i]){ // Print out the passed or failed test results
            cout<<"Test:"<<i+1<<" Passed"<<endl;
        }else{cout<<"Test:"<<i+1<<" Failed"<<endl;}
    }
}