#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
//#include "List.h"
//#include "Vector.h"
//#include "Bitmap.h"
using namespace std;


struct Entry
{
    char key[17];        //´¢´æÃû×Ö×Ö·û´®
    int value;           //Ñ¡Æ±Êý
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

public:
   Entry Max;
   Hashtable(int c = 100);
   ~Hashtable();
   int size() { return N; }
   void put(char *, int);
   //int get(char* k);
   //bool remove(K k);
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

//template <typename K,typename V>
//class Hashtable
//{
//private:
//    Vector<List<Entry<K,V>*>*> ht;
//    int M;
//    int N;

//    ListNode<Entry<K,V>*>* hash(K k);
//    List<Entry<K,V>*>* hash_free(K k);

//public:
//    Entry<K,V> Max;
//    Hashtable(int c=100)
//    {
//       // M=primeNLT(c,1048576,"prime-1048576-bitmap.txt");
//        M=1000;
//        N=0;
//        for(int i=0;i<M;i++)
//        {
//            ht.insert(new List<Entry<K,V>*>());
//        }
//        Max.key="";
//        Max.value=0;
//    }
//    int size(){return N;}
//    void put(K,V);       //ÔÊÐíÖØ¸´
//    V* get(K k);
//    //bool remove(K k);

//    void output()
//    {
//        for(int i=0;i<M;i++)
//        {
//            ListNode<Entry<K,V>*>* p=ht[i]->first();
//            int n=ht[i]->size();
//            if(n==0) {//cout<<"-"<<endl;
//                      continue;}
//            while(0<n--)
//            {
//                cout<<p->data->key<<','<<p->data->value<<' ';
//                p=p->succ;
//            }
//            cout<<endl;
//        }
//    }

//};



#include "Hashtable_implementation.h"

#endif // HASHTABLE_H
