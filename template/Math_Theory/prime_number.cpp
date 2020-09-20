//质数内容
//(1) 质数的判定
//      试除法判质数 O(sqrt(n))
//
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;
vector<int> s;
int n;
bool is_prime(int n)
{
    if(n==1)
        return false;
    for (int i = 2; i <= n / i;i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}

int main()
{
    cin >> n;
    for(int i=0;i < n;i++)
    {
        int x;
        cin>>x;
        s.push_back(x);
    }
    for(auto item:s)
    {
        if(is_prime(item))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}