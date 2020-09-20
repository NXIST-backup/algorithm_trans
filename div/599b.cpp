#include<iostream>
#include<cstring>
using namespace std;
int k;
const int N=2e4+5;
int n;
string s,t;
bool p[N];
int main()
{
	cin>>k;
	while(k--)
	{
	    memset(p,0,sizeof p);
	    int flag=0;
		cin>>n;
		cin>>s>>t;
		int count=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]==t[i])
				p[i]=1;
			else
				count++;
		}
		if(count>=3)
		flag=0;
		else
	    {
		for(int i=0;i<n;i++)
		{
			if(p[i])
				continue;
			for(int j=0;j<n;j++)
			{
				if(!p[j])
				{
					swap(s[i],t[j]);
					if(s==t)
					{
						flag=1;
						break;
					}
					else
						swap(s[i],t[j]);
				}
			}
		}
	    }
		if(flag)
		cout<<"Yes"<<endl;
		else
		cout<<"No"<<endl;
	}
}