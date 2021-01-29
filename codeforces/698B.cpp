/*
  Problem Name:Nezzar and Lucky Number
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

int t;
int Q, d;
int st[11];

bool check(int x)
{
    int res = x % 10;
    if (x >= st[res])
        return true;

    return false;
}
int main()
{
    cin >> t;
    while (t--) {
        cin >> Q >> d;
        memset(st, 0x3f, sizeof st);
        for (int i = 1; i <= 10; i++) {
            int tmp = d * i % 10;
            st[tmp] = min(st[tmp], d * i);
        }
        for (int i = 0; i <= 9; i++) {
            st[i] = min(d * 10 + i, st[i]);
        }
        for (int i = 1; i <= Q; i++) {
            int x;
            cin >> x;
            if (check(x)) {
                cout << "YES" << endl;
                continue;
            }
            cout << "NO" << endl;
        }
    }
}