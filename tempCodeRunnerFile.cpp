#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    int N;
    cin>>N;
    int arr[N];
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
    }
   int res=0;
    for(int i=0;i<N;i++)
    {
        int dig=arr[i]%10;
        arr[i]/=10;
        int x=pow(10,dig);
        int y=arr[i]%x;
        arr[i]/=x;
        res+=pow(arr[i],y);
    }
    cout<<res<<endl;
}