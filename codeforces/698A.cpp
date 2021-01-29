/*
  Problem Name:Nezzar and Colorful Balls
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
const int mod = 1e9 + 7;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

const int N = 105;

int t;
int n;
int st[N];

int main()
{
    iosf;
    cin >> t;

    while (t--) {
        memset(st, 0, sizeof st);
        cin >> n;

        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            st[x]++;
        }
        int mx = 0;
        for (int i = 1; i < N; i++) {
            mx = max(mx, st[i]);
        }

        cout << mx << endl;
    }
}