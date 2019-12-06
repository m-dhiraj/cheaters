#include "files.h"
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
        files::files(){
            path="/";
        }
        files::files(string p){
            path=p;
        }
        void files::setPath(string p){
            path=p;
        }
        string files::getPath(){
            return path;
        }

        int files::loadFiles(){
            DIR *dp;
            struct dirent *dirp;
            if((dp  = opendir(path.c_str())) == NULL) {
                cout << "Error(" << errno << ") opening " << path << endl;
                return errno;
            }

            while ((dirp = readdir(dp)) != NULL) {
                names.push_back(string(dirp->d_name));
            }
            closedir(dp);
            names.erase(names.begin());
            names.erase(names.begin());
            return 0;
        }
        void files::printFiles(){
            for(int i=0; i<names.size(); i++){
                cout << i << " " <<names[i]<<endl;
            }
        }
        int files::numOfFiles(){
            return names.size();
        }
        string files::getFilePath(int i){
            return path+"/"+names[i];
        }
        string files::fileNames(int i){
            return names[i];
        }