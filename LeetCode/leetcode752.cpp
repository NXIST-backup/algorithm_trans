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
    bool state[10005];
    int path[10005];
    int to_int(string s)
    {
        int res = 0;
        int p = 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            res += p * (s[i] - '0');
            p *= 10;
        }
        return res;
    }
    int bfs(int st, int ed)
    {
        queue<int> q;
        q.push(st);
        path[st] = 1;
        while (q.size()) {
            int u = q.front();
            q.pop();
            int p = 1;
            for (int i = 0; i < 4; i++) {
                int num = u / p % 10; // 1, 10,100,1000
                int v = u - num * p;
                int num1, num2;
                if (num == 9)
                    num1 = 0;
                else
                    num1 = num + 1;
                if (num == 0)
                    num2 = 9;
                else
                    num2 = num - 1;
                v += num1 * p;
                if (!state[v] && !path[v]) {
                    q.push(v);
                    path[v] = path[u] + 1;
                }
                v -= num1 * p;
                v += num2 * p;
                if (!state[v] && !path[v]) {
                    q.push(v);
                    path[v] = path[u] + 1;
                }
                p *= 10;
            }
        }

        if (path[ed])
            return path[ed] - 1;
        else
            return -1;
    }
    int openLock(vector<string> &deadends, string target)
    {
        memset(state, 0, sizeof state);
        memset(path, 0, sizeof path);
        int st = 0, ed = to_int(target);

        for (int i = 0; i < deadends.size(); i++) {
            string s = deadends[i];
            int num = to_int(s);
            state[num] = 1;
        }
        if (state[st])
            return -1;
        else
            return bfs(st, ed);
    }
};
int main()
{
    Solution a;
    vector<string> s = {"0201", "0101", "0102", "1212", "2002"};
    string ed = "0202";

    cout << a.openLock(s, ed) << endl;
}