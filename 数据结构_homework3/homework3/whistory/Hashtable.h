#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
using namespace std;


struct Entry
{
    char key[10001];
    int value;
    Entry(){}
    Entry(char* k,int v):value(v){
        strcpy(key,k);
    }
    Entry(Entry const& e): value(e.value){
        strcpy(key,e.key);
    }
    bool operator<(Entry const& e){return strcmp(key,e.key)<0;}
    bool operator>(Entry const& e){return strcmp(key,e.key)>0;}
    bool operator==(Entry const& e){return strcmp(key,e.key)==0;}
    bool operator!=(Entry const& e){return strcmp(key,e.key)!=0;}
};



class Hashtable
{
private:
   Entry** ht;
   int M;
   int N;
   int Len;
public:
   Hashtable(int c = 100,int l=0);
   ~Hashtable();
   void put(char *, int);
   void output()
   {
       for(int i=0;i<M;i++)
       {
           if(ht[i])
           {
               cout<<ht[i]->key<<','<<ht[i]->value<<endl;
           }
       }
   }
};

#include "Hashtable_implementation.h"

#endif // HASHTABLE_H
