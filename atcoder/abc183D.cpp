/*
  Problem Name:Water Heater
  algorithm tag:离散化 差分
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

ll n, w;
const int N = 2e5 + 5;
ll s[N];
ll pre[N];
vector<int> lis;
map<int, int> mp, st;
int S[N], T[N], P[N];
int main()
{
    cin >> n >> w;

    for (int i = 1; i <= n; i++) {
        int s, t, p;
        cin >> s >> t >> p;
        S[i] = s, T[i] = t, P[i] = p;
        if (!st[s]) {
            lis.push_back(s);
            st[s]++;
        }
        if (!st[t]) {
            lis.push_back(t);
            st[t]++;
        }
    }
    sort(lis.begin(), lis.end());
    int idx = 0;
    for (auto item : lis) {
        mp[item] = ++idx;
    }
    for (int i = 1; i <= n; i++) {
        pre[mp[S[i]]] += P[i];
        pre[mp[T[i]]] -= P[i];
    }
    for (int i = 1; i < idx; i++) {
        s[i] = s[i - 1] + pre[i];
    }
    bool is_valid = true;
    for (int i = 1; i < idx; i++) {
        if (s[i] > w) {
            is_valid = false;
            break;
        }
    }
    if (is_valid)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}