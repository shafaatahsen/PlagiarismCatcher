/* HashMap Class
 * Plagiarism Catcher by Felipe Palacios and Ahmad Ahsen
 * EE312 Priebe
 * */

#ifndef PLAGIARISMCATCHER_HASHMAP_H
#define PLAGIARISMCATCHER_HASHMAP_H


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
    HashNode(){
        value = -1;
        next = NULL;
    }

    //returns Hashnode value stored
    unsigned int getValue(){
        return  value;
    }


    void setValue(unsigned int v){
        value = v;
    }
    //returns next HashNode value
    HashNode* getNext(){
        return next;
    }
    void setNext(HashNode* setTo){
        next = setTo;
    }
};

class HashMap{
private:
   static const unsigned long tableSize = 231643;


public:
    HashNode *table[231643];

    HashMap(){
        for(int i = 0; i < tableSize; i++){
            table[i] = NULL;
        }
    }

    //Hashing function for string key
    //input: string key
    //rVal: index within hash table to store value
    unsigned long hashFunc(deque<string> k);

    unsigned long getTableSize(){
        return tableSize;
    }

    //Stores HashNode within location in Hashtable specified
    //input: value to be stored
    //rVal: 0 upon success
    int insertNode(int idx, int val);


};

#endif //PLAGIARISMCATCHER_HASHMAP_H
