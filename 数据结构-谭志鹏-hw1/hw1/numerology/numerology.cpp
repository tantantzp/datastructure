#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

int N;
long long D;
long long Min=0;
int number[25]={0};
char mark[24];

bool isFind=false;

void tryon(int start,long long prevSum,char prevMark);

long long toDigital(int start,int end);

int main()
{

    cin>>N>>D;
    memset(mark,'.',sizeof(char)*24);
    for(int i=0;i<N;i++) cin>>number[i];
    
    Min=3333333333333333333;         //��һ��������ʼ���ӽ�Ŀ�����Сֵ 
    tryon(0,0,'+');
    cout<<"No"<<endl;
    if(isFind)
	   cout<<Min<<endl;
    else 
	   cout<<0<<endl;
    return 0;
}

void tryon(int start,long long prevSum,char prevMark)   //��֦���� 
{
    for(int i=start;i<N;i++)
    {
        long long sum=toDigital(start,i);
        if(sum<0) return;
        if(prevMark=='+') sum+=prevSum;
        else  sum*=prevSum;
        if(sum<0) return;           //��ֹ��������� 
        if(i==N-1)
        {
            if(sum==D)
            {          
               for(int i=0;i<N;i++)
               {
                   cout<<number[i];
                   if(mark[i]!='.') cout<<mark[i];
               }
               cout<<endl;
               exit(0);               //�ҵ�����������һ��������Ƴ����� 
            }
            else
            if(sum>D)                 //����Min���Ա��Ҳ�������Ƿ�����ӽ�ֵ 
            {              
                if(sum<Min)
                {
                    Min=sum;
                    isFind=true;
                }
                return;
            }
            else return;
        }
        long long tmp=toDigital(i+1,N-1);          //��֦���1���������ܵ����ֵ��С��Ŀ�� 
        if((tmp>0)&&(sum+tmp<D)&&(sum*tmp<D)) continue;

        long long tmp2=sum;
        for(int j=i+1;j<N;j++)                   //��֦���2���������ܵ���Сֵ���ڵ�ǰ�ҵ�����СֵMin 
        {                                        //�ڶ��ּ�֦���������Զͬѧ���� 
            tmp2+=number[j];
        }

        if(tmp2>Min) continue;

        mark[i]='+';
        tryon(i+1,sum,'+');
        mark[i]='*';
        tryon(i+1,sum,'*');
        mark[i]='.';
    }
}
long long toDigital(int start, int end)        //���ַ�����ת��Ϊ���� 
{
    if(end-start>=19) return -1;
    long long sum=0;
    for(int i=start;i<=end;i++)
    {
        sum+=number[i];
        sum*=10;
    }
    sum/=10;
    return sum;
}
