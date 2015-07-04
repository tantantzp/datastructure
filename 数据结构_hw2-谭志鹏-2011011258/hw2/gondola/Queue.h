#ifndef QUEUE_H
#define QUEUE_H

#include "List.h"

template <typename T>
class Queue:public List<T>
{
public:
    void enqueue(T const& e){insertAsLast(e);}
    T dequeue(){return List<T>::remove(List<T>::first());}
    T& front(){return List<T>::first()->data;}
};

#endif // QUEUE_H
