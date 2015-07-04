#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

using namespace std;

//以下向量的实现参考了数据结构教材中的实现 

#define DEFAULT_CAPACITY 10

template<typename T> class Vector
{
public:
    int size;                                 
    int capacity;                             
    T* elem;                                 
protected:   
    virtual void expand();                            //指数扩容
    virtual void shrink();                            //压缩
public:
    void copy(T* const A,int lo,int hi);      
    Vector(int cap=DEFAULT_CAPACITY){elem=new T[capacity=cap];size=0;}

    Vector(T* const A,int lo,int hi){copy(A,lo,hi);}

    Vector(T* const A,int n){copy(A,0,n);}    

    Vector(Vector<T> const& V,int lo,int hi){copy(V.elem,lo,hi);} 

    Vector(Vector<T>& V){copy(V.elem,0,V.getSize());}

    ~Vector(){delete[] elem;}

    int getSize(){return size;}                  
    bool empty(){return size<=0;}             

    int insert(int r,T const& e);             //在秩为r处插入元素
    int insert(T const& e) {return insert(size,e);} //在数组末端插入
    int remove(int lo,int hi);                //删除[lo,hi)之间的元素
    T remove(int r);                          //删除秩为r的元素
    virtual void output(int lo,int hi);
    virtual void output();

    T& operator[](int r)const;                
    Vector<T>& operator=(Vector<T>);   

};


#include "vector_implenentation.h"

#endif // VECTOR_H
