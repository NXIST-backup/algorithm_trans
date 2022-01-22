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
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-4;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
//#define x first
//#define y second
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

const int N = 505;

int a[N], b[N];

int main()
{
    char c;
    scanf("%c", &c);
    int idx = 1;
    while (true) {
        scanf("[%d,%d]", &a[idx], &b[idx]);
        scanf("%c", &c);
        if (c == ']')
            break;
        scanf("%c", &c);
        idx++;
    }
    vector<pii> samex;

    for (int i = 1; i <= idx; i++) {
        for (int j = i + 1; j <= idx; j++) {
            if (a[i] == a[j])
                samex.push_back({i, j});
        }
    }
    int ans = 0x3f3f3f3f;
    for (int i = 0; i < samex.size(); i++) {
        for (int j = i + 1; j < samex.size(); j++) {
            int x1 = samex[i].first, y1 = samex[i].second;
            int x2 = samex[j].first, y2 = samex[j].second;
            if ((b[x1] == b[x2] && b[y1] == b[y2])) {
                ans = min(ans, (abs(b[x1] - b[y1]) * abs(a[x1] - a[x2])));
            } else if (b[x1] == b[y2] && b[y1] == b[x2]) {
                ans = min(ans, (abs(b[x1] - b[y1]) * abs(a[x1] - a[y2])));
            }
        }
    }

    cout << ans << endl;
}