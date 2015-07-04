#ifndef QSORT_H
#define QSORT_H

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

/*bool compare(char* a,char* b)
{
    string tmp1(a);
    string tmp2(b);
    return tmp1>=tmp2;
}*/

bool compare(char* a,char* b)         //比较字符串大小，基本按照ASCII表，不过要调整'/'的优先级 
{
    for(int i=0;;i++)
    {
        if(a[i]=='\0' || b[i]=='\0')
        {
            if(b[i]=='\0')
                return true;
            else return false;
        }
        if(a[i]==b[i]){}
        else
        {
            if(a[i]=='/' || b[i]=='/')
            {
                if(a[i]=='/')
                    return false;
                else return true;
            }
            if(b[i]>a[i])
                return false;
            else return true;
        }
    }
}

int QSortPart(char** dir,int low,int high)   //快排算法 
{
    char key[255];
    strcpy(key,dir[low]);
    while(low<high)
    {
         while(low<high && compare(dir[high],key))--high;
         strcpy(dir[low],dir[high]);
         while(low<high && compare(key,dir[low])) ++ low;
         strcpy(dir[high],dir[low]);
    }
    strcpy(dir[low],key);
    return low;
}


void QuickSort(char** dir,int low,int high)
{

    if (low<high)
    {
         int KeyPos = QSortPart(dir,low,high);

         QuickSort(dir,low,KeyPos-1);
         QuickSort(dir,KeyPos+1,high);
    }
}



#endif // QSORT_H
