/*
  Problem Name:
  algorithm tag:greedy 贪心 前缀和
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
const int mod = 1e9 + 7;
typedef pair<int, int> pii;

const int N = 2e5 + 5;

int n;

ll pre[N];
int pos[N];
//傻逼了一直忘加ll
int main()
{
    cin >> n;
    ll maxn = -1e9;
    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        pre[i] = pre[i - 1] + x;
        if (pre[i] > maxn) {
            maxn = pre[i];
            pos[i] = i;
        } else
            pos[i] = pos[i - 1];
    }
    ll ans = 0;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += pre[pos[i]];
        if (ans < sum)
            ans = sum;
        sum -= pre[pos[i]];
        sum += pre[i];
    }

    cout << ans << endl;
}