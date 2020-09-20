//区间分组

#include <functional>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>
#include <cstdio>
#include <vector>

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
    cin >> n;

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        qujian.push_back({l, r});
    }
    sort(qujian.begin(), qujian.end(), cmp);

    priority_queue<int, vector<int>, greater<int>> heap;
    int ans = 0;
    for (auto item : qujian) {
        if (heap.size()) {
            if (item.first <= heap.top()) {
                ans++;
                heap.push(item.second);
            } else {
                heap.pop();
                heap.push(item.second);
            }
        }else {
            ans++;
            heap.push(item.second);
        }
    }
    cout << ans << endl;
}