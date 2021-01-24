/*
  Problem Name:最大子序和
  algorithm tag:DP
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e9;
typedef pair<int, int> pii;

const int N = 3e5 + 5;
int s[N];
int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] += s[i - 1];
    }

    deque<int> q;
    q.push_back(0);
    int res = -1e9;
    for (int i = 1; i <= n; i++) {
        if (q.size() && i - q.front() > m)
            q.pop_front();
        res = max(res, s[i] - s[q.front()]);
        while (q.size() && s[i] <= s[q.back()])
            q.pop_back();
        q.push_back(i);
    }
    cout << res << endl;
}