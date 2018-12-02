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

        if (myFile.is_open())
        {
            while ( getline (myFile,line) )
            {
                cout << line << '\n';
            }
            myFile.close();
        }

    }

    FILE *fptr;
    vector <char>  eqn;
    strcpy(eqn, files[2]);
    fptr = fopen(eqn, "r");

    if (fptr == NULL) {  //if nothing in file deosn't work
        printf("Nothing has opened!\n");
        exit(-1);
    } else {        //if file has pointer in it then it works
        printf("file open\n");
    }

    return 0;
}