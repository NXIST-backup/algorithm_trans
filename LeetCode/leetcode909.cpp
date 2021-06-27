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
    int n;
    int state[505];
    int dist[505];
    int bfs(int st)
    {
        memset(dist, 0, sizeof dist);
        queue<int> q;
        q.push(st);
        dist[st] = 1;
        while (q.size()) {
            int u = q.front();
            q.pop();

            for (int i = 1; i <= 6; i++) {
                int v = u + i;
                if (state[v] != -1)
                    v = state[v];
                if (!dist[v]) {
                    q.push(v);
                    dist[v] = dist[u] + 1;
                }
            }
        }

        if (dist[n * n])
            return dist[n * n] - 1;
        else
            return -1;
    }
    int snakesAndLadders(vector<vector<int>> &board)
    {
        memset(state, 0, sizeof state);

        n = board.size();
        bool po = 1;
        int idx = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (po == 1) {
                for (int j = 0; j < n; j++)
                    state[idx++] = board[i][j];
                po = !po;
            } else {
                for (int j = n - 1; j >= 0; j--)
                    state[idx++] = board[i][j];
                po = !po;
            }
        }
        for (int i = 1; i <= 25; i++) {
            cout << state[i] << " ";
            if (i % 5 == 0)
                cout << endl;
        }
        return bfs(1);
    }
};
int main()
{
    Solution a;

    vector<vector<int>> board = {
        {-1, -1, 19, 10, -1},
        {2, -1, -1, 6, -1},
        {-1, 17, -1, 19, -1},
        {25, -1, 20, -1, -1},
        {-1, -1, -1, -1, 15}};

    cout << a.snakesAndLadders(board) << endl;
}