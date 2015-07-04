#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

using namespace std;

#define DEFAULT_CAPACITY 10

template<typename T> class Vector     //�����࣬�������ݽṹ�̲�
{
public:
    int size;                                 //ʵ�ʹ�ģ
    int capacity;                             //����
    T* elem;                                  //������
protected:   
    void expand();                            //ָ������
    void shrink();                            //ѹ��

public:
    void copy(T* const A,int lo,int hi);      //�������临��
    Vector(int cap=DEFAULT_CAPACITY){elem=new T[capacity=cap];size=0;}//Ĭ�Ϲ��캯��

    Vector(T* const A,int lo,int hi){copy(A,lo,hi);}//�������临��

    Vector(T* const A,int n){copy(A,0,n);}    //�������帴��

    Vector(Vector<T> const& V,int lo,int hi){copy(V.elem,lo,hi);} //�������临��

    Vector(Vector<T>& V){copy(V.elem,0,V.getSize());}

    ~Vector(){delete[] elem;}

    int getSize(){return size;}                  //��ģ
    bool empty(){return size<=0;}             //�п�

    int insert(int r,T const& e);             //����Ϊr������Ԫ��
    int insert(T const& e) {return insert(size,e);} //������ĩ�˲���
    int remove(int lo,int hi);                //ɾ��[lo,hi)֮���Ԫ��
    T remove(int r);                          //ɾ����Ϊr��Ԫ��
    void output(int lo,int hi);
    void output();

    int find(T const& e) const;               //�����������
    int find(T const& e,int lo,int hi) const; //�����������

    void sort(int lo,int hi);                 //��������
    void sort(){sort(0,size);}

    T& operator[](int r)const;                //�����±������
    Vector<T>& operator=(Vector<T>);   //���ظ��Ʋ�����

    template<typename VST> void traverse(VST&);

};


#include "vector_implenentation.h"

#endif // VECTOR_H
