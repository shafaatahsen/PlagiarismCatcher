#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "plagiarismCatcher.h"
#include <string.h>
#include <stdio.h>
#include <deque>
#include <sstream>
#include "hashMap.h"

using namespace std;



int main(int argc, char* argv[])
{

    string dir = string(argv[1]);
    int k = atoi(argv[2]);
    string line;
    vector<string> files = vector<string>();

    getdir(dir,files);
    HashMap h;  //need this to use hashFunc

    for (unsigned int i = 2;i < files.size();i++) {
        cout << i << files[i] << endl;
        string fPath = dir + "/" + files[i];

        ifstream myFile (fPath.c_str());
        deque<string> cue;

        if (myFile.is_open())
        {
            while ( getline (myFile,line) )
            {
                istringstream iss(line);
                string word;
                while(iss >> word){
                    if(cue.size() == 6){
                        for(deque<string>::iterator iter = cue.begin(); iter != cue.end(); iter++){
                            cout<<*iter;
                        }
                        unsigned long hashedIdx = h.hashFunc(cue);
                        h.insertNode(hashedIdx,i); //key: 6 word, value: file number
                        cout<<endl;
                        cout << hashedIdx << endl;
                        cue.pop_front();
                    }
                    cue.push_back(word);
                }


                /*int j = 0;
                while(line[j] != NULL){
                    if(cue.size() == 6){
                        for(deque<string>::iterator iter = cue.begin(); iter != cue.end(); iter++){
                            cout<<*iter;
                        }
                        cout<<endl;
                        cue.pop_front();
                    }

                }*/
            }
            myFile.close();
        }

    }



    return 0;
}