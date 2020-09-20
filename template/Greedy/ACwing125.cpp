//耍杂技的牛

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

int n;
vector<pii> niu;
bool cmp(pii a, pii b)
{
    return a.first+a.second<b.first+b.second;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        int w, s;
        cin >> w >> s;
        niu.push_back({w,s});
    }
    sort(niu.begin(), niu.end(), cmp);
    int ans = -2e9;
    int weight=0;
    for (auto item : niu) {
        ans=max(ans,weight-item.second);
        weight += item.first;
    }
    cout << ans << endl;
}