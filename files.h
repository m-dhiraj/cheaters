#ifndef files_h
#define files_h
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class files{
    private:
        string path;
        vector<string> names;

    public:
        files();
        files(string p);
        void setPath(string p);
        string getPath();
        int loadFiles();
        void printFiles();
        int numOfFiles();
        string getFilePath(int i);
        string fileNames(int i);
};
#endif