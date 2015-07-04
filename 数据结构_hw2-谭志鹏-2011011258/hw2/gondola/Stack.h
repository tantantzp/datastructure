#ifndef STACK_H
#define STACK_H

#include "Vector.h"
//#define MAX_INT 2147483647

template <typename T>
class Stack:public Vector<T>
{
public:
    void push(T e){Vector<T>::insert(e);}
    T pop(){return Vector<T>::remove(Vector<T>::size-1);}
    T& top(){return Vector<T>::elem[Vector<T>::size-1];}
};


#endif // STACK_H
