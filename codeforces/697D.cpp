/*
  Problem Name:Cleaning the Phone
  algorithm tag: 二分
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
int n, m;
pii all[N];

bool cmp2(ll a, ll b)
{
    if (a > b)
        return true;
    else
        return false;
}

int main()
{
    cin >> t;

    while (t--) {
        cin >> n >> m;

        for (int i = 1; i <= n; i++)
            cin >> all[i].first;
        for (int i = 1; i <= n; i++)
            cin >> all[i].second;
        vector<ll> a, b;
        a.push_back(0);
        b.push_back(0);
        for (int i = 1; i <= n; i++)
            if (all[i].second == 1)
                a.push_back(all[i].first);
            else
                b.push_back(all[i].first);

        sort(a.begin() + 1, a.end(), cmp2);
        sort(b.begin() + 1, b.end(), cmp2);

        for (int i = 1; i < a.size(); i++) {
            a[i] += a[i - 1];
        }
        for (int i = 1; i < b.size(); i++) {
            b[i] += b[i - 1];
        }
        int ans = INF;

        for (int i = 0; i < a.size(); i++) {
            int res = i;
            int sum = a[i];
            int idx = lower_bound(b.begin(), b.end(), m - a[i]) - b.begin();
            //cout << idx << endl;
            if (idx < b.size())
                sum += b[idx];
            if (sum >= m) {
                res += idx * 2;
                ans = min(res, ans);
            } else
                continue;
        }

        if (ans != INF)
            cout << ans << endl;
        else
            cout << -1 << endl;
    }
}