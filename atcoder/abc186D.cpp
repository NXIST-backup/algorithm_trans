/*
  Problem Name:Sum of difference
  algorithm tag:前缀和
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
int a[N];
ll pre[N];

bool cmp(int a, int b)
{
    if (a > b)
        return true;
    else
        return false;
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll sum = 0;
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + a[i];
    for (int i = 1; i < n; i++) {
        sum += 1ll * (n - i) * a[i];
    }
    ll sum2 = 0;
    for (int i = 1; i < n; i++) {
        sum2 += pre[n] - pre[i];
    }
    cout << abs(sum - sum2) << endl;
}
