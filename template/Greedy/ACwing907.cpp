//区间覆盖

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>
#include <wchar.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e9;
typedef pair<int, int> pii;
vector<pii> qujian;
int n;

bool cmp(pii a, pii b)
{
    return a.first < b.first;
}

int main()
{
    int s, e;
    cin >> s >> e;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        qujian.push_back({l, r});
    }
    sort(qujian.begin(), qujian.end(), cmp);
    // for (auto item : qujian)
    //     cout<<item.first<<" "<<item.second<<endl;
    int ans = 1;
    int start = s;
    int max_r = s;
    bool flag = 0;
    for (auto item : qujian) {
        if (item.first <= start) {
            if (item.second > max_r) {
                max_r = item.second;
            }
        } else if (item.first <= max_r) {
            ans++;
            start = max_r;
            if (item.second > max_r)
                max_r = item.second;
        } else
            break;
        if (max_r >= e) {
            flag = 1;
            break;
        }
    }
    if (flag)
        cout << ans << endl;
    else
        cout << -1 << endl;
}