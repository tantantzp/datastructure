/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

typedef int Rank; //��
#define DEFAULT_CAPACITY  3 //Ĭ�ϵĳ�ʼ������ʵ��Ӧ���п�����Ϊ����

template <typename T> class Vector { //����ģ����
private:
   Rank _size; int _capacity;  T* _elem; //��ģ��������������
protected:
   void copyFrom(T const * A, Rank lo, Rank hi); //������������A[lo, hi)
   void expand(); //�ռ䲻��ʱ����
   void shrink(); //װ�����ӹ�Сʱѹ��
   bool bubble(Rank lo, Rank hi); //ɨ�轻��
   void bubbleSort(Rank lo, Rank hi); //���������㷨
   void Vector<T>::exchange(Rank i, Rank j); //Ԫ�ؽ���
   Rank selectMax(Rank lo, Rank hi); //ѡȡ���Ԫ��
   void selectionSort(Rank lo, Rank hi); //ѡ�������㷨
   void merge(Rank lo, Rank mi, Rank hi); //�鲢�㷨
   void mergeSort(Rank lo, Rank hi); //�鲢�����㷨
   Rank partition(Rank lo, Rank hi); //��㹹���㷨
   void quickSort(Rank lo, Rank hi); //���������㷨
   void heapSort(Rank lo, Rank hi); //�������Ժ�����ȫ�ѽ��⣩
public:
// ���캯��
   Vector(int c = DEFAULT_CAPACITY) { _elem = new T[_capacity = c]; _size = 0; } //Ĭ��
   Vector(T const * A, Rank lo, Rank hi) { copyFrom(A, lo, hi); } //�������临��
   Vector(T const * A, Rank n) { copyFrom(A, 0, n); } //�������帴��
   Vector(Vector<T> const & V, Rank lo, Rank hi) { copyFrom(V._elem, lo, hi); } //�������临��
   Vector(Vector<T> const & V) { copyFrom(V._elem, 0, V._size); } //�������帴��
// ��������
   ~Vector() { delete [] _elem; } //�ͷ��ڲ��ռ�
// ֻ�����ʽӿ�
   Rank size() const { return _size; } //��ģ
   bool empty() const { return _size <= 0; } //�п�
   int disordered() const; //�ж������Ƿ�������
   Rank find(T const & e) const { return find(e, 0, (Rank)_size); } //���������������
   Rank find(T const & e, Rank lo, Rank hi) const;//���������������
   Rank search(T const & e) const  //���������������
      { return (0 >= _size) ? -1 : search(e, (Rank)0, (Rank)_size); }
   Rank search(T const & e, Rank lo, Rank hi) const;//���������������
// ��д���ʽӿ�
   T & operator[](Rank r) const; //�����±������������������������ʽ���ø�Ԫ��
   Vector<T> & operator=(Vector<T> const &); //���ظ�ֵ���������Ա�ֱ�ӿ�¡����
   T remove(Rank r); //ɾ����Ϊr��Ԫ��
   int remove(Rank lo, Rank hi); //ɾ����������[lo,hi)֮�ڵ�Ԫ��
   Rank insert(Rank r, T const & e); //����Ԫ��
   Rank insert(T const & e) { return insert(_size, e); } //Ĭ����ΪĩԪ�ز���
   void sort(Rank lo, Rank hi); //��[lo, hi)����
   void sort() { sort(0, _size); } //��������
   void unsort(Rank lo, Rank hi); //��[lo, hi)����
   void unsort() { unsort(0, _size); } //��������
   int deduplicate(); //����ȥ��
   int uniquify(); //����ȥ��
// ����
   void traverse(void (*)(T &)); //������ʹ�ú���ָ�룬ֻ����ֲ����޸ģ�
   template <typename VST> void traverse(VST &); //������ʹ�ú������󣬿�ȫ�����޸ģ�
}; //Vector

#include "vector_implementation.h"