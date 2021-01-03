#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int k;
int n;
const int N=1005;
int a[N];
int h[N];
 
int main()
{
	cin>>k;
	while(k--)
	{
	    memset(h,0,sizeof h);
	    memset(a,0,sizeof a);
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int x;
			cin>>x;
			a[x]++;
		}
		for(int i=1000;i>=1;i--)
		{
			h[i]=h[i+1]+a[i];
		}
		for(int i=1000;i>=1;i--)
		{
			if(h[i]>=i)
			{
			    cout<<i<<endl;
			    break;
			}
		}
	}
}