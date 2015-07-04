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

class Bitmap { //位图Bitmap类
private:
   char* map; int N; //以char（8比特）为单位的比特图map，及其长度（以sizeof(char)为单位）
protected:
   void init(int n) { map = new char[N = (n+7)/8]; memset(map, 0, N); }
public:
   Bitmap(int n = 8) { init(n); } //按指定（或默认）规模创建比特图（为测试暂时选用较小的默认值）
   Bitmap(char* file, int n = 8) //按指定（或默认）规模，从指定文件中读取比特图
   {  init(n); FILE* fp = fopen(file, "r"); fread(map, sizeof(char), N, fp); fclose(fp);  }
   ~Bitmap() { delete [] map; map = NULL; } //析构时释放比特图空间
   void set  (int k) { expand(k);        map[k >> 3] |=  (0x80 >> (k & 0x07)); }
   void clear(int k) { expand(k);        map[k >> 3] &= ~(0x80 >> (k & 0x07)); }
   bool test (int k) { expand(k); return map[k >> 3] &   (0x80 >> (k & 0x07)); }
   void dump (char* file)
   {  FILE* fp = fopen(file, "w"); fwrite(map, sizeof(char), N, fp); fclose(fp);  }
   char* bits2string(int n) { //将前n位转换为字符串——应由上层调用者负责释放，尽管这里为了简化省了这一步
      expand(n-1); //此时可能被访问的最高位为bitmap[n-1]
      char* s = new char[n+1]; s[n] = '\0';
      for (int i = 0; i < n; i++) s[i] = test(i) ? '1' : '0'; //*DSA*/printf("%s\n", s);
      return s;
   }
   void print(int n)
   {  expand(n); for (int i = 0; i < n; i++) printf(test(i) ? "1" : "0");  }
   void expand(int k) { //若被访问的Bitmap[k]已出界，则需扩容
      if (k < 8*N) return; //仍在界内，无需扩容
      int oldN = N; char* oldMap = map;
      init(2*k); //与向量类似，加倍策略
      memcpy_s(map, N, oldMap, oldN); delete [] oldMap;
      //*DSA*/printf("\tBITMAP resized from %d to %d\n", oldN, N);
   }
};