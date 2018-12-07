/*
 * Plagiarism Catcher by Felipe Palacios and Ahmad Ahsen
 * EE312 Priebe
 * main function*/

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
#include <stdlib.h>

using namespace std;



int main(int argc, char* argv[])
{

    string dir = string(argv[1]);
    int k = atoi(argv[2]);
    int collisions = atoi(argv[3]);
    string line;
    vector<string> files = vector<string>();

    getdir(dir,files);
    HashMap h;  //need this to use hashFunc

    vector<string>::iterator iter;

    for(iter = files.begin(); iter != files.end();iter++){
        if((*iter == "..") || (*iter == "."))
            files.erase(iter);
    }
    for(iter = files.begin(); iter != files.end();iter++){
        if((*iter == "..") || (*iter == "."))
            files.erase(iter);
    }


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

                        unsigned long hashedIdx = h.hashFunc(cue);
                        h.insertNode(hashedIdx,i); //key: 6 word, value: file number

                        cue.pop_front();
                    }
                    cue.push_back(word);
                }

            }
            myFile.close();
        }



    }

    //Initialize table for grid
    int table[files.size()][files.size()];
    for(int l= 0; l < files.size(); l++){
	    for(int m = 0; m < files.size(); m++){
	        table[l][m] = 0;
	    }
    }


    //Loop through hash table and count how many collisions there are
    //Pair Collisions
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

    //Loop through table of collisions and print if they are larger than the size specified by the user
    for(int i = 0; i<files.size();i++ ){

        for (int j = i+1; j < files.size(); j++) {
            if(table[i][j] >= collisions){
                cout<<files[i]<<" and "<<files[j]<<" have "<<table[i][j]<<" collisions"<<endl;
            }

        }
    }



    return 0;
}
