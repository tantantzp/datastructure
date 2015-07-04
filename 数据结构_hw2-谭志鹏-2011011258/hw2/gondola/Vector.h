#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

using namespace std;

#define DEFAULT_CAPACITY 10

template<typename T> class Vector
{
public:
    int size;                                 //ʵ�ʹ�ģ
    int capacity;                             //����
    T* elem;                                  //������
protected:   
    void expand();                            //ָ������
    void shrink();                            //ѹ��

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

    int insert(int r,T const& e);              //����Ϊr������Ԫ��
    int insert(T const& e) {return insert(size,e);} //������ĩ�˲���
    int remove(int lo,int hi);                //ɾ��[lo,hi)֮���Ԫ��
    T remove(int r);                          //ɾ����Ϊr��Ԫ��
    void output(int lo,int hi);
    void output();
    int find(T const& e) const;               //�����������
    T& operator[](int r)const;                //�����±������
    Vector<T>& operator=(Vector<T>);          //���ظ�ֵ������
};


#include "Vector_implenentation.h"

#endif // VECTOR_H
