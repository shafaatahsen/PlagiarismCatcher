#include "hashMap.h"
#include <cmath>
#include <vector>

unsigned long HashMap::hashFunc(deque<string> k) {

    unsigned long hash = 0;
    for(int i = 0; i < k.size(); i++){  //uses method 3 from slides
        if((k[i] > 0x40 && k[i] <0x5B) && k[i] < 0x7B) {    //only lets letters through
            if(k[i] > 0x40 && k[i] < 0x61) {
                k[i] += 0x20;   //makes upper case letters lower case
            }
                hash += k[i] * (int) pow(13.0, i);

        }
    }
    return hash % tableSize;
}