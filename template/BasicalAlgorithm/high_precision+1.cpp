#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main()
{
    string a,b;
    int A[100050]={0};
    int B[100050]={0};
    int C[100050]={0};
    cin>>a>>b;
    for(int i=a.size()-1,j=0;i>=0;i--,j++)
    A[i]=a[j]-'0';
    for(int i=b.size()-1,j=0;i>=0;i--,j++)
    B[i]=b[j]-'0';
    int len1=a.size();
    int len2=b.size();
    int i=0;
    for(;i<len1&&i<len2;i++)
    {
        C[i]=C[i]+A[i]+B[i];
        if(C[i]>=10)
        {
            C[i]=C[i]-10;
            C[i+1]=C[i+1]+1;
        }
    }
    while(i<len1)
    {
        C[i]+=A[i];
        i++;
    }
    while(i<len2)
    {
        C[i]+=B[i];
        i++;
    }
    int flag=1;
    int j=i;
    if(C[j]>0)
    {
        cout<<C[j];
    }
    j--;
    for(;j>=0;j--)
    cout<<C[j];
}
