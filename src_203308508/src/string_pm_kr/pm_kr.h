/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

/*DSA*/#include <string.h>

#define M 97 //散列表长度：既然这里并不需要真地存储散列表，不妨取更大的素数，以降低误判的可能
#define R 10 //基数：对于二进制串，取2；对于十进制串，取10；对于ASCII字符串，取128或256
#define DIGIT(S, i) ((S)[i]-'0')  //取十进制串S的第i位数字值（假定S合法）
typedef __int64 HashCode; //用64位整数实现散列码
                           /*DSA*/#define showProgressOfKR(T, P, k) { \
                           /*DSA*/ showProgress(T, P, k, 0); \
                           /*DSA*/ printf("hashT = %I64d", hashT); getchar(); \
                           /*DSA*/ }
bool check1by1(char* P, char* T, size_t i);
HashCode prepareDm(size_t m);
void updateHash(HashCode &hashT, char* T, size_t m, size_t k, HashCode Dm);