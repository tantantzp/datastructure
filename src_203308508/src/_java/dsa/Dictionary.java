/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/*
 * �����򣩴ʵ�ṹ�ӿ�
 */

package  dsa;

public interface Dictionary {
   //��ѯ�ʵ�ṹ��ǰ�Ĺ�ģ
   public int getSize();

   //�жϴʵ�ṹ�Ƿ�Ϊ��
   public boolean isEmpty();

   //���ʵ��д�����keyΪ�ؼ������Ŀ���򷵻����е�һ����Ŀ�����򣬷���null
   public Entry find(Object key);

   //�����ɹؼ���Ϊkey����Ŀ��ɵĵ�����
   public Iterator findAll(Object key);

   //������Ŀ(key, value)�������ظ���Ŀ
   public Entry insert(Object key, Object value);

   //���ʵ��д�����keyΪ�ؼ������Ŀ����ժ�����е�һ�������أ����򣬷���null
   public Entry remove(Object key);

   //���شʵ���������Ŀ��һ��������
   public Iterator entries();
}