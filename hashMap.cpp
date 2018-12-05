#include "hashMap.h"
#include <cmath>
#include <vector>

unsigned long HashMap::hashFunc(deque<string> k) {
    int getMod(int base, int p, unsigned long size);
    unsigned long hash = 0;
    int power = 0;
    for(int i = 0; i < k.size(); i++){  //uses method 3 from slides this is for the # of strings in queue
        for(int j = 0; j < k[i].size(); j++) {  //this is the the actual characters in the of the string
            if ((k[i][j] > '@' && k[i][j] < '[') || k[i][j] < '{') {    //only lets letters through
                if (k[i][j] > '@' && k[i][j] < 'a') {
                    k[i][j] += (char) ' ';   //makes upper case letters lower case
                }
                hash += k[i][j] * getMod(13,power, tableSize) ;
                power++;
            }
        }
    }
    return hash % tableSize;
}

int getMod(int base, int p, unsigned long size){
    if(p == 0){
        return 1;
    }
    if(p == 1){
        return (int)base;
    }
    else if(p%2 == 0){
        return (getMod(base,p/2,size)*getMod(base,p/2,size))%(int)size;
    }
    else return ((getMod(base,p/2, size)*getMod(base,p/2, size)*base))%(int)size;

}