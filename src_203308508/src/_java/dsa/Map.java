/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/*
 * ӳ��ṹ�ӿ�
 */

package  dsa;

public interface Map {
   //��ѯӳ��ṹ��ǰ�Ĺ�ģ
   public int getSize();

   //�ж�ӳ��ṹ�Ƿ�Ϊ��
   public boolean isEmpty();

   //��ӳ���д�����keyΪ�ؼ������Ŀ���򷵻ظ���Ŀ�����ݶ��󣻷��򣬷���null
   public Object get(Object key);

   //��ӳ���в�������keyΪ�ؼ������Ŀ���������Ŀ(key, value)������null
   //���򣬽�������Ŀ�����ݶ����滻Ϊvalue��������ԭ�ȵ����ݶ���
   public Object put(Object key, Object value);

   //��ӳ���д�����keyΪ�ؼ������Ŀ����ɾ��֮�����������ݶ��󣻷��򣬷���null
   public Object remove(Object key);

   //����ӳ����������Ŀ��һ��������
   public Iterator entries();
}