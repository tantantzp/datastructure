#ifndef VECTOR_CPP_H
#define VECTOR_CPP_H

#pragma once

//以下向量的实现参考了数据结构教材中的实现 

template <typename T>
void Vector<T>::copy(T * A, int lo, int hi)
{
    elem=new T[(hi-lo)*2];
    size=0;
    while(lo<hi)
    {
        elem[size++]=A[lo++];

    }
}


template <typename T>
T& Vector<T>::operator[](int r) const
{
    if(r>=0&&r<size)  return elem[r];
}


template <typename T> Vector<T>& Vector<T>::operator=(Vector<T> V )
{
   if (elem) delete [] elem;

   elem=new T[V.getSize()*2];
   size=0;
   for(int i=0;i<V.getSize();i++)
   {
       insert(V[i]);
   }
   return *this;
}

template <typename T>
void Vector<T>::expand()
{
    if(size<capacity) return;
    if(capacity<DEFAULT_CAPACITY) capacity=DEFAULT_CAPACITY;
    T* oldElem=elem;
    elem=new T[capacity<<=1];
    for(int i=0;i<size;i++)
    {
        elem[i]=oldElem[i];
    }
    delete []oldElem;
    //cout<<capacity<<endl;
}

template <typename T>
void Vector<T>::shrink()
{
    if(capacity>>1<DEFAULT_CAPACITY) return;
    if(size>capacity>>2) return;
    T* oldElem=elem;
    elem=new T[capacity>>=1];
    for(int i=0;i<size;i++)
    {
        elem[i]=oldElem[i];
    }
    delete []oldElem;
}

template <typename T>
int Vector<T>::insert(int r, const T &e)
{
    expand();
    for(int i=size;i>r;i--)
    {
        elem[i]=elem[i-1];
    }
    elem[r]=e;
    size++;
    return r;
}

template <typename T>
int Vector<T>::remove(int lo, int hi)
{
    if(lo>=hi || hi>size ||lo<0) return -1;
    while(hi<size)
    {
        elem[lo++]=elem[hi++];
    }
    size=lo;
    shrink();
    return hi-lo;
}

template <typename T>
T Vector<T>::remove(int r)
{
    T tmp=elem[r];
    remove(r,r+1);
    return tmp;
}


template <typename T>
void Vector<T>::output(int lo, int hi)
{
    for(int i=lo;i<hi;i++)
    {
        cout<<elem[i]<<' ';
    }
    cout<<endl;
}

template <typename T>
void Vector<T>::output()
{
    output(0,size);
}

#endif // VECTOR_CPP_H
