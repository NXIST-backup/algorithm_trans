#include<iostream>
using namespace std;
const int N=100005;
int a[N];
int b[N];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    for(int i=1;i<=m;i++)
    {
        int l,r,c;
        cin>>l>>r>>c;
        b[l]+=c;//从l到最后的数都加上c
        b[r+1]-=c;//从r+1到最后的数都减去c，所以l到r都加上c。
    }
    for(int i=1;i<=n;i++)
    {
        b[i]+=b[i-1];
    }
    for(int i=1;i<=n;i++)
    cout<<a[i]+b[i]<<" ";
}
