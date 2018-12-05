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

using namespace std;



int main()
{
    string dir = string("sm_doc_set");
    string line;
    vector<string> files = vector<string>();

    getdir(dir,files);

    for (unsigned int i = 0;i < files.size();i++) {
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
                        cout<<endl;
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