#ifndef PLAGIARISMCATCHER_HASHMAP_H
#define PLAGIARISMCATCHER_HASHMAP_H
#endif //PLAGIARISMCATCHER_HASHMAP_H

#include<iostream>
#include <deque>

using namespace std;

class HashNode{
private:
    unsigned int value;  //how many times we've seen the node
    HashNode *next; //
public:
    HashNode(unsigned int v){
        value = v;
        next = NULL;
    }

    unsigned int getValue(){
        return  value;
    }
    void setValue(unsigned int v){
        value = v;
    }
    HashNode* getNext(){
        return next;
    }
    void setNext(HashNode* setTo){
        next = setTo;
    }
};

class HashMap{
private:
    const unsigned long tableSize = 1000007;
    HashNode* table[];

public:
    void makeTable(){
        for(int i = 0; i < tableSize; i++){
            table[i] = NULL;
        }
    }

    unsigned long hashFunc(deque<string> k);

    unsigned long getTableSize(){
        return tableSize;
    }

};
