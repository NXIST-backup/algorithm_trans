//(3)筛质数
// 埃式筛O(nloglogn)


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

const int N = 1e6 + 50;

int n;
int cnt;
bool st[N];
int prime[N];


void get_prime(int x)
{
    for (int i = 2; i <= n;i++)
    {
        if(!st[i])
        {
            prime[cnt++] = i;
            st[i] = true;
            for (int j = i + i; j <= n;j+=i)
                st[j] = true;
        }
    }
}




int main()
{
    cin >> n;

    get_prime(n);

    cout << cnt << endl;
}