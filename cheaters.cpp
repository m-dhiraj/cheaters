#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include<stdio.h> 
#include "chunker.h"
#include "files.h"
#include "hashTable.h"
using namespace std;

int main(int argc, char *argv[])
{
    string path = argv[1];
    files f(path);
    f.loadFiles();
    //f.printFiles();
    int num; 
    sscanf(argv[2], "%d", &num);
    hashTable h;
    for(int i=0; i<f.numOfFiles();i++){
        chunker c(num);
        c.loadWords(f.getFilePath(i));
        c.createChunks();
        for(int j=0;j<c.chunks.size();j++){
            //hash it
            h.addKey(h.hash(c.chunks[j]),i);
            //put it in the hash table
        }
    }
    //go through each hash table entry and record number of file occurences
    int **matrix=h.getMatrix(f.numOfFiles());
    int r=0;
    for(int i=0;i<f.numOfFiles();i++){
        for(int j=0;j<f.numOfFiles();j++){

        }
    }
}