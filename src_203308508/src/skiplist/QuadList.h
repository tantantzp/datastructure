/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "QuadlistNode.h" //����Quadlist�ڵ���
template <typename T> class Quadlist { //Quadlistģ����
private:
   int _size; QuadlistNodePosi(T) header; QuadlistNodePosi(T) trailer; //��ģ��ͷ�ڱ���β�ڱ�
protected:
   void init(); //Quadlist����ʱ�ĳ�ʼ��
   int clear(); //������нڵ�
public:
// ���캯��
   Quadlist() { init(); } //Ĭ��
// ��������
   ~Quadlist() { clear(); delete header; delete trailer; } //ɾ�����нڵ㣬�ͷ��ڱ�
// ֻ�����ʽӿ�
   Rank size() const { return _size; } //��ģ
   bool empty() const { return _size <= 0; } //�п�
   QuadlistNodePosi(T) first() const { return header->succ; } //�׽ڵ�λ��
   QuadlistNodePosi(T) last() const { return trailer->pred; } //ĩ�ڵ�λ��
   bool valid(QuadlistNodePosi(T) p) //�ж�λ��p�Ƿ����Ϸ�
      { return (trailer != p) && (header != p); }
// ��д���ʽӿ�
   T remove(QuadlistNodePosi(T) p); //ɾ�����Ϸ���λ��p���Ľڵ㣬���ر�ɾ���ڵ����ֵ
   QuadlistNodePosi(T) //��*e��Ϊp�ĺ�̡�b�����ڲ���
   insertAfterAbove(T const & e, QuadlistNodePosi(T) p, QuadlistNodePosi(T) b = NULL);
// ����
   void traverse(void (*)(T&)); //�������ڵ㣬����ʵʩָ������������ָ�룬ֻ����ֲ��޸ģ�
   template <typename VST> //������
   void traverse(VST&); //�������ڵ㣬����ʵʩָ���������������󣬿�ȫ�����޸Ľڵ㣩
}; //Quadlist

#include "Quadlist_implementation.h"