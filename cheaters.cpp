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
    int maxFiles; 
    sscanf(argv[3], "%d", &maxFiles);
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
    // //cout<<matrix[0]<<endl;

     int r=0;
     while(r<(f.numOfFiles()*f.numOfFiles())){
         r++;
         int max=0;
         int mr=0;
         int mc=0;
     for(int i=0;i<f.numOfFiles();i++){
         for(int j=0;j<f.numOfFiles();j++){
            
             if(matrix[i][j]>max){
                 max=matrix[i][j];
                 mr=i;
                 mc=j;
         }
         }
     }
         if(max>=maxFiles){
             cout<<matrix[mr][mc]<<": "<<f.fileNames(mr)<<", "<<f.fileNames(mc)<<endl;
             matrix[mr][mc]=0;
             matrix[mc][mr]=0;
         }
     }
}