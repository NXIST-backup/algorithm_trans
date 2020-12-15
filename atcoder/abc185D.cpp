/*
  Problem Name:Stamp
  algorithm tag: 模拟
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

const int M = 2e5 + 5;

int n, m;
int blue[M];
vector<int> seg;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> blue[i];
    sort(blue + 1, blue + 1 + m);
    int st = 1;

    for (int i = 1; i <= m; i++) {
        int ed = blue[i];
        if (ed - st > 0)
            seg.push_back(ed - st);
        st = ed + 1;
    }
    if (n - st + 1 > 0)
        seg.push_back(n - st + 1);
    sort(seg.begin(), seg.end());
    int cut = 0;
    if (seg.size())
        cut = seg[0];
    int ans = 0;
    for (auto item : seg) {
        if (item % cut)
            ans += item / cut + 1;
        else
            ans += item / cut;
    }
    cout << ans << endl;
}