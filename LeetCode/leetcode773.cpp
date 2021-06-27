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

class Solution
{
  public:
    map<vector<int>, int> dist;
    int off[4] = {
        -3,
        3,
        -1,
        1,
    };
    int bfs(vector<int> start, vector<int> ed)
    {
        queue<vector<int>> q;
        q.push(start);
        dist[start] = 1;
        while (q.size()) {
            auto t = q.front();
            if (t == ed)
                break;
            q.pop();
            int pos = -1;
            for (int i = 0; i < t.size(); i++)
                if (t[i] == 0) {
                    pos = i;
                    break;
                }
            for (int i = 0; i < 4; i++) {
                int pos1 = pos + off[i];
                if (pos1 < 0 || pos1 > 5)
                    continue;
                if (pos == 2 && pos1 == 3)
                    continue;
                if (pos == 3 && pos1 == 2)
                    continue;
                auto v = t;
                swap(v[pos1], v[pos]);
                if (!dist[v]) {
                    q.push(v);
                    dist[v] = dist[t] + 1;
                }
            }
        }
        if (dist[ed])
            return dist[ed] - 1;
        else
            return -1;
    }
    int slidingPuzzle(vector<vector<int>> &board)
    {
        vector<int> start = board[0];
        for (auto i : board[1])
            start.push_back(i);
        vector<int> ed = {1, 2, 3, 4, 5, 0};

        return bfs(start, ed);
    }
};

int main()
{
    Solution a;
    vector<vector<int>> list = {{3, 2, 4},
                                {1, 5, 0}};
    cout << a.slidingPuzzle(list) << endl;
}