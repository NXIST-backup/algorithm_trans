/*
  Problem Name:单词接龙
  algorithm tag:DFS
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
//#define x first
//#define y second
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

int n;
string s[22];
string start;
int st[22];
string ans;

void dfs(string start)
{
    if (start.size() > ans.size()) {
        ans = start;
    }

    for (int i = 0; i < n; i++) {
        if (st[i] >= 2)
            continue;
        int len = 0;
        for (int j = 1; j <= min(start.size(), s[i].size()); j++) {
            string sub1 = start.substr(start.size() - j, j);
            string sub2 = s[i].substr(0, j);
            if (sub1 == sub2) {
                len = j;
                break;
            }
        }
        if (len == 0)
            continue;
        st[i]++;
        start += s[i].substr(len, s[i].size() - len);
        dfs(start);
        st[i]--;
        int tmp = s[i].size() - len;
        while (tmp--)
            start.pop_back();
    }
}

int main()
{
    iosf;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> s[i];

    cin >> start;

    dfs(start);

    cout << ans.size() << endl;
}