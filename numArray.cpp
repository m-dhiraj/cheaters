#include "numArray.h"
        numArray::numArray(){
            r=1;
            array = new int*[r];
            array[0]=new int[r];
            array[0][0]=0;
        }
        numArray::numArray(int l){
            r=l;
            array = new int*[r];
            for(int i=0; i<r; i++){
                array[i]=new int[r];
            }
            for(int i=0;i<r;i++)
                for(int g=0;g<r;g++)
                {
                    array[i][g]=0;
                }
        }
        void numArray::incValue(int row, int col){
            if(row!=col)
                array[row][col]+=1;
        }
        int numArray::getValue(int row, int col){
            return array[row][col];
        }