#ifndef chunker_h
#define chucker_h
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class chunker{
    private:
        
        int chunkSize;
    public:
        vector<string> words;
        vector<string> chunks;
        chunker();
        chunker(int s);
        void loadWords(string path);
        void createChunks();
};
#endif