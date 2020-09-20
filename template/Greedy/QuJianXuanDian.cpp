#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stdio.h>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e9;
typedef pair<int, int> pii;
int n;
vector<pii> qujian;
bool cmp(pii a, pii b)
{
    if (a.second < b.second)
        return true;
    else
        return false;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        qujian.push_back({l, r});
    }

    sort(qujian.begin(), qujian.end(), cmp);
    int flag = -1e9 - 3;
    int ans = 0;
    for (auto item : qujian) {
        // cout << item.first << " " << item.second << endl;]
        if (item.first <= flag)
            continue;
        else {
            flag = item.second;
            ans++;
        }
    }
    cout << ans << endl;
}