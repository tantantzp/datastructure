#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include "cstring"
#include "Hashtable.h"

using namespace std;

int main()
{
    int N;
    scanf("%d\n",&N);
    Hashtable table(100017);   //创建散列类
    char tmp[40];
    char a[20];
    int num=0;
    for(int i=0;i<N;i++)
    {
        gets(tmp);         //手动解析输入，加快读入速度
        int len=strlen(tmp);
        int j=0;

        while(tmp[j]!=' ')
        {
            a[j]=tmp[j++];
        }
        a[j++]='\0';
        while(tmp[j++]==' ');
        j--;
        num=0;
        while(j<len)
        {
            if(tmp[j]==' ') break;
            num=num*10+(int)(tmp[j++]-'0');
        }

        table.put(a,num);
    }
    cout<<table.Max.key<<' '<<table.Max.value<<endl;
    return 0;
}

