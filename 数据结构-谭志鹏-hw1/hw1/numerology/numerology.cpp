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
    
    Min=3333333333333333333;         //以一个大数初始化接近目标的最小值 
    tryon(0,0,'+');
    cout<<"No"<<endl;
    if(isFind)
	   cout<<Min<<endl;
    else 
	   cout<<0<<endl;
    return 0;
}

void tryon(int start,long long prevSum,char prevMark)   //剪枝搜索 
{
    for(int i=start;i<N;i++)
    {
        long long sum=toDigital(start,i);
        if(sum<0) return;
        if(prevMark=='+') sum+=prevSum;
        else  sum*=prevSum;
        if(sum<0) return;           //防止长整形溢出 
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
               exit(0);               //找到满足条件的一个结果即推出程序 
            }
            else
            if(sum>D)                 //更新Min，以便找不到结果是返回最接近值 
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
        long long tmp=toDigital(i+1,N-1);          //剪枝情况1：后续可能的最大值都小于目标 
        if((tmp>0)&&(sum+tmp<D)&&(sum*tmp<D)) continue;

        long long tmp2=sum;
        for(int j=i+1;j<N;j++)                   //剪枝情况2：后续可能的最小值大于当前找到的最小值Min 
        {                                        //第二种剪枝情况受尚泽远同学启发 
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
long long toDigital(int start, int end)        //将字符数组转化为数字 
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
