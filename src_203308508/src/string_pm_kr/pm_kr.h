/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

#pragma once

/*DSA*/#include <string.h>

#define M 97 //ɢ�б��ȣ���Ȼ���ﲢ����Ҫ��ش洢ɢ�б�����ȡ������������Խ������еĿ���
#define R 10 //���������ڶ����ƴ���ȡ2������ʮ���ƴ���ȡ10������ASCII�ַ�����ȡ128��256
#define DIGIT(S, i) ((S)[i]-'0')  //ȡʮ���ƴ�S�ĵ�iλ����ֵ���ٶ�S�Ϸ���
typedef __int64 HashCode; //��64λ����ʵ��ɢ����
                           /*DSA*/#define showProgressOfKR(T, P, k) { \
                           /*DSA*/ showProgress(T, P, k, 0); \
                           /*DSA*/ printf("hashT = %I64d", hashT); getchar(); \
                           /*DSA*/ }
bool check1by1(char* P, char* T, size_t i);
HashCode prepareDm(size_t m);
void updateHash(HashCode &hashT, char* T, size_t m, size_t k, HashCode Dm);