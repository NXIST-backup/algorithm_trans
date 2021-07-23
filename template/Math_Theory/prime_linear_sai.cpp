//线性筛
//  O(n)
//  n只会被他的最小质因子删除
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

const int N = 1e6 + 50;

int prime[N];
int n;
int st[N];
int cnt;

void get_prime(int x)
{
    for (int i = 2; i <= x; i++) {
        if (!st[i])
            prime[cnt++] = i;
        for (int j = 0; prime[j] <= x / i; i++) //最小质因子不可能超过sqrt(n)
        {
            st[i * prime[j]] = true; //
            if (i % prime[j] == 0)   //pj一定是i的最小质因子，pj也一定是pj*i的最小质因子
                break;               //为什么要break掉，原因是每个合数只被它最小的质因子筛一次
        }
    }
}

int main()
{
    freopen("1.in", "w", stdout);

    cin >> n;

    get_prime(n);
    cout << cnt << endl;
    for (int i = 0; i < cnt; i++)
        cout << prime[i] << " ";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
