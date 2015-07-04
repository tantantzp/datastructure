#include <iostream>

using namespace std;

int N,M;
struct fib             //fib�ṹ��ͬʱ��¼���ڵ�����쳲������� 
{      
    unsigned long long  fib1;
    unsigned long long  fib2;
};

fib caculate(int n);

int main()
{
    
    cin>>N>>M;
    fib result=caculate(N);
    cout<<result.fib1<<endl;
    
    return 0;
}


fib caculate(int n)      
{
    if(n<=50)              //�ݹ���ڣ�n��Сʱֱ�Ӽ��� 
    {
        int f=1,g=0;
        while(0<n--)      //��쳲����������������ݽṹ�̲� 
        {
            f=f+g;
            g=f-g;
            f=f%M;
            g=g%M;
        }
        struct fib tmp;
        tmp.fib1=f;
        tmp.fib2=g;
        return tmp;      //ͬʱ��������������fib�� 
    }
    else                //n�ϴ�ʱ���ö��ּ����㷨����쳲�������������ż������� 
    {
        if(n%2==0)
        {
            fib num=caculate(n/2-1);
   
            unsigned long long tmp1=(num.fib1+num.fib2)%M;
            unsigned long long tmp2=num.fib1;
            unsigned long long tmp3=num.fib2;
            unsigned long long tmp4=((tmp1*tmp1)+(tmp2*tmp2))%M;
            unsigned long long tmp5=((tmp2*tmp2)+(tmp3*tmp3))%M;
            num.fib1=tmp4%M;    
            if(tmp4<tmp5) 
			    num.fib2=(tmp4-tmp5+M)%M;
            else  
			    num.fib2=(tmp4-tmp5)%M;
            return num;
        }
        else
        {
            fib num=caculate(n-1);
            unsigned long long tmp1=num.fib1;
            unsigned long long tmp2=num.fib2;
            num.fib1=(tmp1+tmp2)%M;
            num.fib2=tmp1;

            return num;
        }
    }


}
