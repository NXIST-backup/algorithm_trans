#include<iostream>
using namespace std;
typedef long long ll;
int main()
{
    ll a,b,p;
    ll ans=1%p;
    cin>>a>>b>>p;
    while(b)
    {
        if(b&1)
        {
            ans=ans*a%p;
        }
        a=a*a%p;
        b>>=1;
    }
    cout<<ans;
}