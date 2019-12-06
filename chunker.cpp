#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include "chunker.h"

        chunker::chunker(){
            chunkSize=6;
        }
        chunker::chunker(int s){
            chunkSize=s;
        }
        void chunker::loadWords(string path){
             ifstream inFile;
             inFile.open(path.c_str());
             string word;
             while(inFile>>word){
                 for(int i=0;i<word.length();i++){
                     if(!isalnum(word[i])||word[i]==' ')
                        word.erase(i--,1);
                 }
                 transform(word.begin(), word.end(), word.begin(), ::tolower);
                 words.push_back(word);
             }
        }
        void chunker::createChunks(){
            for(int i=0;i<=words.size()-chunkSize;i++){
                string chu="";
                for(int r=0;r<chunkSize;r++){
                    chu+=words[i+r];
                }
                chunks.push_back(chu);
              
            }
        }