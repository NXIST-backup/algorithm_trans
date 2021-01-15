/*
  Problem Name: 数字转换
  algorithm tag: 树的直径，树形DP
*/
//tips:只要边权为正都可以使用bfs or dfs两次的做法求树的直径(贪心做法)
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

const int N = 50005;

vector<int> g[N];
int n;
int st[N];
int idx;
void bfs(int start)
{
    queue<int> q;
    q.push(start);

    while (q.size()) {
        int t = q.front();
        q.pop();

        for (auto v : g[t]) {
            if (!st[v]) {
                q.push(v);
                st[v] = st[t] + 1;
                idx = v;
            }
        }
    }
}

int main()
{
    cin >> n;

    for (int i = 2; i <= n; i++) {
        int v = 1;
        for (int j = 2; j <= sqrt(i); j++) {
            if (j == i)
                continue;
            if (i % j == 0) {
                if (j != i / j)
                    v += j + i / j;
                else
                    v += j;
            }
        }
        if (v < i) {
            g[i].push_back(v);
            g[v].push_back(i);
        }
    }
    bfs(1);
    memset(st, 0, sizeof st);
    bfs(idx);

    cout << st[idx] << endl;
}