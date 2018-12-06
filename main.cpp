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

    vector<string>::iterator iter;
    cout<<files[0]<<endl;
    cout<<files[1]<<endl;
    for(iter = files.begin(); iter != files.end();iter++){
        if((*iter == "..") || (*iter == "."))
            files.erase(iter);
    }
    cout<<files[0]<<endl;
    cout<<files[1]<<endl;

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
                        /*for(deque<string>::iterator iter = cue.begin(); iter != cue.end(); iter++){
                            cout<<*iter;
                        }*/
                        unsigned long hashedIdx = h.hashFunc(cue);
                        h.insertNode(hashedIdx,i); //key: 6 word, value: file number
                        //cout<<endl;
                        //cout << hashedIdx << endl;
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

    int table[files.size()][files.size()] ={0};


    for(int i = 0; i<h.getTableSize();i++){
        if(h.table[i]==NULL){
            continue;
        }
        HashNode *temp = h.table[i];
        HashNode *temp2;
        while(temp->getNext() != NULL){
            temp2= temp->getNext();
            if(temp->getValue()<temp2->getValue()){
                table[temp->getValue()][temp2->getValue()]++;
            }
            else{
                table[temp2->getValue()][temp->getValue()]++;
            }
            HashNode *used = temp;
            temp = temp->getNext();
            delete(used);
        }
        delete(temp);

    }
    for(int i = 0; i<files.size();i++ ){

        for (int j = i+1; j < files.size(); j++) {
            if(table[i][j]>0){
                cout<<files[i]<<" and "<<files[j]<<" have "<<table[i][j]<<" collisions"<<endl;
            }

        }
    }



    return 0;
}