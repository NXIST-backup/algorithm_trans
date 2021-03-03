/*
  Problem Name:Ball in Berland
  algorithm tag:
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

const int N = 2e5 + 5;

int t;
int a, b, k;
int p1[N], p2[N];
int st1[N], st2[N];
int main()
{
    cin >> t;

    while (t--) {
        cin >> a >> b >> k;
        memset(st1, 0, sizeof st1);
        memset(st2, 0, sizeof st2);
        for (int i = 1; i <= k; i++) {
            cin >> p1[i];
            st1[p1[i]]++;
        }
        for (int i = 1; i <= k; i++) {
            cin >> p2[i];
            st2[p2[i]]++;
        }
        ll ans = 0;
        int tmp = k;
        for (int i = 1; i <= k; i++) {
            ans += tmp - st1[p1[i]] - st2[p2[i]] + 1;
            st1[p1[i]]--;
            st2[p2[i]]--;
            tmp--;
        }
        if (ans > 0)
            cout << ans << endl;
        else
            cout << 0 << endl;
    }
}

int cmp(int a, int b)
{
    cout << 1 << endl;
}