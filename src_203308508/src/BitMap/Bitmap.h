/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

#pragma warning(disable : 4996 4800)
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include "../_share/release.h"

class Bitmap { //λͼBitmap��
private:
   char* map; int N; //��char��8���أ�Ϊ��λ�ı���ͼmap�����䳤�ȣ���sizeof(char)Ϊ��λ��
protected:
   void init(int n) { map = new char[N = (n+7)/8]; memset(map, 0, N); }
public:
   Bitmap(int n = 8) { init(n); } //��ָ������Ĭ�ϣ���ģ��������ͼ��Ϊ������ʱѡ�ý�С��Ĭ��ֵ��
   Bitmap(char* file, int n = 8) //��ָ������Ĭ�ϣ���ģ����ָ���ļ��ж�ȡ����ͼ
   {  init(n); FILE* fp = fopen(file, "r"); fread(map, sizeof(char), N, fp); fclose(fp);  }
   ~Bitmap() { delete [] map; map = NULL; } //����ʱ�ͷű���ͼ�ռ�
   void set  (int k) { expand(k);        map[k >> 3] |=  (0x80 >> (k & 0x07)); }
   void clear(int k) { expand(k);        map[k >> 3] &= ~(0x80 >> (k & 0x07)); }
   bool test (int k) { expand(k); return map[k >> 3] &   (0x80 >> (k & 0x07)); }
   void dump (char* file)
   {  FILE* fp = fopen(file, "w"); fwrite(map, sizeof(char), N, fp); fclose(fp);  }
   char* bits2string(int n) { //��ǰnλת��Ϊ�ַ�������Ӧ���ϲ�����߸����ͷţ���������Ϊ�˼�ʡ����һ��
      expand(n-1); //��ʱ���ܱ����ʵ����λΪbitmap[n-1]
      char* s = new char[n+1]; s[n] = '\0';
      for (int i = 0; i < n; i++) s[i] = test(i) ? '1' : '0'; //*DSA*/printf("%s\n", s);
      return s;
   }
   void print(int n)
   {  expand(n); for (int i = 0; i < n; i++) printf(test(i) ? "1" : "0");  }
   void expand(int k) { //�������ʵ�Bitmap[k]�ѳ��磬��������
      if (k < 8*N) return; //���ڽ��ڣ���������
      int oldN = N; char* oldMap = map;
      init(2*k); //���������ƣ��ӱ�����
      memcpy_s(map, N, oldMap, oldN); delete [] oldMap;
      //*DSA*/printf("\tBITMAP resized from %d to %d\n", oldN, N);
   }
};