#ifndef hashTable_h
#define hashTable_h
#include <vector>
#include <errno.h>
#include <string>
#include <iostream>

using namespace std;

struct Node{
    int index;
    Node *next;
};

class hashTable{
    private:
        static const int MAX_SIZE =1000000;
        Node *t[MAX_SIZE]={};

    public:
        unsigned int hash(string s);
        void addKey(unsigned int index, int fileLoc);
        void clear();

};

#endif