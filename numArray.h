#ifndef numArray_h
#define numArray_h
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class numArray{
    private:
        int **array;
        int r;
    public:
        numArray();
        numArray(int l);
        void incValue(int row, int col);
        int getValue(int row, int col);
};
#endif