#include<iostream>
#include<vector>
#include<string>


using namespace std;


vector<int> jian(vector<int> a,vector<int> b)
{

}

int main()
{
    string a,b;
    cin>>a>>b;  
    vector<int> A;
    vector<int> B;
    for(int i=a.size()-1;i>=0;i--)
    A.push_back(a[i]-'0');
    for(int i=b.size()-1;i>=0;i--)
    B.push_back(b[i]-'0');
    
}