/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename Tv, typename Te> //����DFS�����������㷨
Stack<Tv>* Graph<Tv, Te>::tSort(int s) { //assert: 0 <= s < n
   reset(); int clock = 0; int v = s;
   Stack<Tv>* S = new Stack<Tv>; //��ջ��¼���򶥵�
   do {
      if (UNDISCOVERED == status(v))
         if (!TSort(v, clock, S)) { //clock���Ǳ���
            /*DSA*/print(S);
            while (!S->empty()) S->pop(); break; //��һ��ͨ���༴��ͼ����DAG����ֱ�ӷ���
         }
   } while (s != (v = (++v % n)));
   return S; //������ΪDAG����S�ڸ������Զ�������򣻷��򣨲������������򣩣�S��
}

template <typename Tv, typename Te> //����DFS�����������㷨�����ˣ�
bool Graph<Tv, Te>::TSort(int v, int& clock, Stack<Tv>* S) { //assert: 0 <= v < n
   dTime(v) = ++clock; status(v) = DISCOVERED; //���ֶ���v
   for (int u = firstNbr(v); -1 < u; u = nextNbr(v, u)) //ö��v�������ھ�u
      switch (status(u)) { //����u��״̬�ֱ���
         case UNDISCOVERED:
            parent(u) = v; status(v, u) = TREE;
            if (!TSort(u, clock, S)) return false; //�Ӷ���u������
            break;
         case DISCOVERED:
            status(v, u) = BACKWARD; //һ�����ֺ���ߣ���DAG������
            return false; //�˳�����������
         default: //VISITED (digraphs only)
            status(v, u) = (dTime(v) < dTime(u)) ? FORWARD : CROSS;
            break;
      }
   status(v) = VISITED; S->push(vertex(v)); //���㱻���ΪVISITEDʱ��ջ
   return true;
}