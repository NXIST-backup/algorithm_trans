/*
  Problem Name:Sugoroku2 
  algorithm tag:概率DP,线性方程
*/

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

typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e9;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
const int N = 1e5 + 50;

pdd f[2 * N];
int n, m, k;
bool st[N];

int main()
{
    cin >> n >> m >> k;

    for (int i = 1; i <= k; i++) {
        int x;
        cin >> x;
        st[x] = 1;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (st[i])
            cnt++;
        else
            cnt = 0;
        if (cnt >= m) {
            cout << -1 << endl;
            return 0;
        }
    }

    pdd sum = {0, 0};
    for (int i = n - 1; i >= 0; i--) {
        if (st[i]) {
            f[i] = {1, 0};
        } else {
            f[i] = {sum.first / m,
                    sum.second / m + 1};
        }
        sum.first -= f[i + m].first;
        sum.second -= f[i + m].second;
        sum.first += f[i].first;
        sum.second += f[i].second;
    }

    printf("%.4lf", f[0].second / (1 - f[0].first));
}