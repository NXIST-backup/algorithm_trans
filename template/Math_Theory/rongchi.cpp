//容斥定理
//s(1)-s(2)+s(3)-s(4)....
//
//O(2^n)

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

typedef long long  ll;

int n, m;
int p[20];
int main()
{
    cin >> n >> m;

    for (int i = 0; i < m;i++)
        cin >> p[i];

    int res = 0;
    for (int i = 1; i < 1 << m;i++)//将总共(2^n-1)项化成二进制
    {
        int t = 1, cnt = 0;
        for (int j = 0; j < m;j++)
            if(i>>j&1)
            {
                cnt++;//二进制里1的个数
                if((ll)t*p[j]>n)//???
                {
                    t = -1;
                    break;
                }
                t *= p[j];
            }
        if(t!=-1)
        {
            if(cnt%2)
                res += n / t;
            else
                res -= n / t;
        }
    }
}