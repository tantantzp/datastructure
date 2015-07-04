#include <iostream>
#include <string>

using namespace std;

int main()
{
    int card[10]={-1};
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        card[a]=i;
    }
    string number;
    cin>>number;
    int result=0;
    int p=1;
    for(int i=number.size()-1;i>=0;i--)
    {

        result+=card[int(number[i]-'0')]*p;
        p*=n;
    }
    cout<<result<<endl;
    return 0;
}

