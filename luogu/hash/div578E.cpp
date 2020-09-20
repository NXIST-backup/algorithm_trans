#include<cstring>
#include<iostream>
using namespace std;

const int N=100050,M=1000050,P=131;

typedef unsigned long long ull;

char str1[M],str2[M];
int n;
ull h[M],b[M],p[M];

int main()
{
    p[0]=1;
    for (int i = 1; i <= 1000000;i++)
        p[i] = p[i - 1] * P;
    cin >> n;
    cin>>(str1+1);
    n--;
    while(n--)
    {
    
        //cout << str1+1 << endl;
        str1[0] = 1;
        int x1=strlen(str1);
        //cout << x1 << endl;
        for(int i=1;i<x1;i++)
        {
            b[i]=b[i-1]+(ull)str1[i]*p[i];
        }
        cin>>(str2+1);
        str2[0] = 1;
        int x2=strlen(str2);
        for(int i=1;i<x2;i++)
            h[i]=h[i-1]+(ull)str2[i]*p[i];
        
        //sample please
        //p4p5p6,p1p2p3
        // for (int i = 1; i < x2;i++)
        // {
        //     cout << b[i] << " ";
        // }
        // puts("");
        int t=0;
        for(int i=1;i<min(x1,x2);i++)
        {
            if((b[x1-1]-b[x1-i-1])==h[i]*p[x1-i-1])
                t=i;
        }
        //cout << t << endl;
        for(int i=t+1,sl=0;i<x2;i++,sl++)
        str1[x1+sl]=str2[i];
    }
    cout<<str1+1<<endl;
}