#include <iostream>
#include <fstream>
#include "chunker.h"

        chunker::chunker(){
            chunkSize=6;
        }
        chunker::chunker(int s){
            chunkSize=s;
        }
        void chunker::loadWords(string path){
            ifstream inFile;
            inFile.open(path);
            string word;
            while(inFile>>word){
                words.push_back(word);
                cout<<word<<endl;
            }
        }
        void chunker::createChunks(){
            
        }