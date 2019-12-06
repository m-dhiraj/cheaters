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

/*function... might want it in some class?*/
int getdir (string dir, vector<string> &files)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    files.erase(files.begin());
    files.erase(files.begin());
    return 0;
}

int main(int argc, char *argv[])
{
    string path = argv[1];
    files f(path);
    f.loadFiles();
    //f.printFiles();
    int num; 
    sscanf(argv[2], "%d", &num);
    chunker c(num);
    hashTable h();
    for(int i=0; i<f.numOfFiles;i++){
        c.loadWords(f.getFilePath(i));
        c.createChunks();

    }
    
}