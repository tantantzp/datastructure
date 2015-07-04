/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/*
 * ��Ŀ�ӿ�
 */

package  dsa;

public interface Entry {
   //ȡ��Ŀ�Ĺؼ���
   public Object getKey();
   //�޸���Ŀ�Ĺؼ��룬���ش�ǰ��ŵĹؼ���
   public Object setKey(Object k);

   //ȡ��Ŀ�����ݶ���
   public Object getValue();
   //�޸���Ŀ�����ݶ��󣬷��ش�ǰ��ŵ����ݶ���
   public Object setValue(Object v);
}