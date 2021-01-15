/*
  Problem Name:
  algorithm tag:implement
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

const int N = 3e5 + 5;

int t;
int n;
int st[N];
int a[N];
int main()
{
    cin >> t;
    int idx = 1;
    while (t--) {
        cin >> n;
        vector<int> pos;
        memset(st, 0, sizeof st);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int ans = 0;
        for (int i = 2; i <= n - 1; i++) {
            if (a[i] > a[i + 1] && a[i] > a[i - 1]) {
                pos.push_back(i);
                st[i] = 1;
                ans++;
            }
            if (a[i] < a[i + 1] && a[i] < a[i - 1]) {
                pos.push_back(i);
                st[i] = 1;
                ans++;
            }
        }
        int res = ans;
        for (auto item : pos) {
            if (st[item - 1] && st[item + 1]) {
                res = min(res, ans - 3);
                continue;
            }
            if (!st[item - 1] && !st[item + 1]) {
                res = min(res, ans - 1);
                continue;
            }
            if (st[item - 1] && !st[item + 1]) {
                if (item + 1 == n) {
                    res = min(res, ans - 2);
                    continue;
                }
                if ((a[item + 1] > a[item + 2] && a[item + 1] > a[item - 1]) || (a[item + 1] < a[item + 2] && a[item + 1] < a[item - 1])) {
                    res = min(res, ans - 1);
                } else
                    res = min(res, ans - 2);
                continue;
            }

            if (!st[item - 1] && st[item + 1]) {
                if (item - 1 == 1) {
                    res = min(res, ans - 2);
                    continue;
                }
                if ((a[item - 1] > a[item - 2] && a[item - 1] > a[item + 1]) || (a[item - 1] < a[item - 2] && a[item - 1] < a[item + 1])) {
                    res = min(res, ans - 1);
                } else
                    res = min(res, ans - 2);
                continue;
            }
        }
        cout << res << endl;
    }
}