/*
  Problem Name:
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
const int mod = 1e9 + 7;
typedef pair<int, int> pii;

const int N = 105;
int t;

int n, m;

int r[N], b[N];

int main()
{
    cin >> t;
    while (t--) {
        cin >> n;
        int maxr = 0;
        int maxb = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            r[i] = r[i - 1] + x;
            maxr = max(maxr, r[i]);
        }
        cin >> m;
        for (int i = 1; i <= m; i++) {
            int x;
            cin >> x;
            b[i] = b[i - 1] + x;
            maxb = max(maxb, b[i]);
        }
        int ans = maxr + maxb;
        cout << ans << endl;
    }
}