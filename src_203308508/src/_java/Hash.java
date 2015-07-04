/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/*
 * Example of HashMap and Hashtable in Java
 */
import java.util.*;

public class Hash {
   public static void main(String[] args) {
      HashMap HM = new HashMap();  //Map
      HM.put("����", "̩ɽ");
      HM.put("����", "��ɽ");
      HM.put("����", "��ɽ");
      HM.put("����", "��ɽ");
      HM.put("����", "��ɽ");
      System.out.println(HM);
      Hashtable HT = new Hashtable();  //Dictionary
      HT.put("����", "̩ɽ");
      HT.put("����", "��ɽ");
      HT.put("����", "��ɽ");
      HT.put("����", "��ɽ");
      HT.put("����", "��ɽ");
      System.out.println(HT);
   }
}
