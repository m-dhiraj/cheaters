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
        static const int MAX_SIZE =1000003;
        Node* t[MAX_SIZE];
        

    public:
        hashTable();
        unsigned int hash(string s);
        void addKey(unsigned int index, int fileLoc);
        int** getMatrix(int files);
        void clear();
        void clearHelp(Node* s);
        ~hashTable();
};

#endif