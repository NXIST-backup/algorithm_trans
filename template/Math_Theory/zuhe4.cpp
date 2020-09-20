//
//分解质因数：
//C[a][b] = p1^m1 * p2^m2 * … * pk^mk;其中p1~pk都是1~a中的素数；
//m1~mk是其中对应的每个素数的次数，是在a中的次数 - b 中的次数 - (a - b)中的次数；
//然后再用高精度乘法求出
// 质因子p在a!的次数的算法
// f(a!,p)=a/p+a/p^2+a/p^3...直到p^k>a
// 证明:https://blog.csdn.net/alex_yuqian/article/details/92367397

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

const int N = 5010;

int prime[N], cnt;
int sum[N];
bool st[N];

void get_prime(int n)
{
    for (int i = 2; i <= n;i++)
    {
        if(!st[i])
            prime[cnt++] = i;
        for (int j = 0; prime[j] <= n / i;j++)
        {
            st[prime[j] * i] = true;
            if(i%prime[j]==0)
                break;
        }
    }
}

int get(int n,int p)
{
    int res = 0;
    while (n) {
        res += n / p;
        n /= p;
    }
    return res;
}

vector<int> mul(vector<int>a,int b)
{
    vector<int> c;
    int t = 0;
    for (int i = 0; i < a.size();i++)
    {
        t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }
    while (t) {
        c.push_back(t % 10);
        t /= 10;
    }
    return c;
}


int main()
{
    int a, b;
    cin >> a >> b;

    get_prime(a);

    for (int i = 0; i < cnt;i++)
    {
        sum[i] = get(a, prime[i]) - get(b, prime[i]) - get(a - b, prime[i]);
    }

    vector<int> res;
    res.push_back(1);

    for (int i = 0; i < cnt;i++)
        for (int j = 0; j < sum[i];j++)
            res = mul(res, prime[i]);

    for (int i = res.size() - 1; i >= 0;i--)
        cout << res[i];
    cout << endl;
    return 0;
}