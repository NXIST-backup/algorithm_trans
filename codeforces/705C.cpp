/*
  Problem Name:K-beautiful Strings
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
int n, k;
string s;
int st[26];

bool check()
{
    bool flag = true;
    for (int i = 0; i < 26; i++) {
        if (st[i] % k) {
            flag = false;
            break;
        }
    }
    return flag;
}
int main()
{
    cin >> t;
    while (t--) {
        memset(st, 0, sizeof st);
        cin >> n >> k;

        cin >> s;
        if (n % k) {
            cout << -1 << endl;
            continue;
        }

        for (int i = 0; i < s.size(); i++) {
            st[s[i] - 'a']++;
        }

        cout << s << endl;
    }
}