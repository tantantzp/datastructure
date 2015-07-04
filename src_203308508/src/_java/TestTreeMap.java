/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-26883-3 & 7-302-29652-2
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2011. All rights reserved.
 ******************************************************************************************/

/*
 * ≤‚ ‘TreeMap
 */
import java.util.*;

public class TestTreeMap {
   public static void main(String[] args) {
      TreeMap scarborough = new TreeMap();
      scarborough.put("P", "parsley");
      scarborough.put("S", "sage");
      scarborough.put("R", "rosemary");
      scarborough.put("T", "thyme");
      System.out.println(scarborough); // {P = parsley, R = rosemary, S = sage, T = thyme}
   }
}
