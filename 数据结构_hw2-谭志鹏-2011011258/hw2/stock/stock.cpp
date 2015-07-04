#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cstring>

using namespace std;

int N=0;
int maxDay=0;
unsigned long long sum=0;
int Max=0;
double average=0.00;

int* stock;
int* flag;
int size=0;
int header=0,tailer=0;         //�б��ͷβ��ʾ 

inline void enqueue(int a,int b);
inline void dequeue(int a);

int main()
{
    scanf("%d\n",&N);
    stock=new int[N];           //���������������header��tailer���ɶ���
    flag=new int[N];             //flag��¼���ù�Ʊ�����Ĺ�Ʊ�� 
    memset(stock,0,N*sizeof(int));
    for(int i=0;i<N;i++) flag[i]=1;
    char tmp1[20];
    for(int i=0;i<2*N;i++)
    {
        gets(tmp1);
        int len=strlen(tmp1);
        int i=0,a=0,b=0;
        bool f=false;
        while(i<len)
        {
            if(tmp1[i]==' ')
            {
                f=true;
                i++;
                break;

            }
            else
            {
                a=a*10+(tmp1[i++]-'0');
            }
        }
        if(f)                    //�����������;����ǽ��ӻ��ǳ��� 
        {
            while(i<len)
            {
                b=b*10+tmp1[i++]-'0';
            }
            enqueue(a,b);
        }
        else
        {
            dequeue(a);
        }


    }
    average=(double)sum/maxDay;
    printf("%.2lf",average);
    delete []stock;
    delete []flag;
    return 0;
}

void enqueue(int a, int b)       //�������У�����ʱ�����ȵ�ǰ�ڵ�С�Ľڵ㣬������¼��flag������ 
{

    int tmp=1;
    while(tailer>header && b>stock[tailer-1])
    {
        tailer--;
        tmp+=flag[tailer];
    }
    stock[tailer]=b;
    flag[tailer++]=tmp;

    maxDay+=a;
    sum+=Max*a;
    Max=stock[header];

}

void dequeue(int a)
{
    if(--flag[header]>0)
    {
        sum+=Max*a;
        maxDay+=a;
    }
    else
    {
        header++;
        sum+=Max*a;
        if(header<tailer)
            Max=stock[header];
        else Max=0;
        maxDay+=a;
    }

}
