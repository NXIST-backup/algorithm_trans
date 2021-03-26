/*
  Problem Name:八数码
  algorithm tag:A star
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
const int INF = 1e9;
const int mod = 1e9 + 7;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, string> pls;
#define x first
#define y second
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

string start, list;

void debug(string s)
{
    for (int i = 0; i < 9; i++) {
        if ((i + 1) % 3)
            cout << s[i];
        else
            cout << s[i] << endl;
    }
    cout << endl;
}

int f(string state)
{
    int res = 0;
    for (int i = 0; i < state.size(); i++)
        if (state[i] != 'x') {
            int t = state[i] - '1';
            res += abs(i / 3 - t / 3) + abs(i % 3 - t % 3);
        }
    return res;
}
string star(string start)
{
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    char c[] = "rdlu";
    string ed = "12345678x";
    priority_queue<pls, vector<pls>, greater<pls>> heap;
    unordered_map<string, int> dist;
    unordered_map<string, pair<string, char>> pre;
    heap.push({f(start), start});
    dist[start] = 0;

    while (heap.size()) {
        auto t = heap.top();
        heap.pop();

        if (t.y == ed)
            break;
        string v = t.y;
        int x1, y1, pos;
        for (int i = 0; i < 9; i++)
            if (v[i] == 'x') {
                x1 = i / 3;
                y1 = i % 3;
                pos = i;
            }
        for (int i = 0; i < 4; i++) {
            if (x1 + dx[i] >= 3 || y1 + dy[i] >= 3 || x1 + dx[i] < 0 || y1 + dy[i] < 0)
                continue;
            int tran = x1 * 3 + dx[i] * 3 + y1 + dy[i];

            swap(v[pos], v[tran]);
            if (!dist.count(v) || dist[v] > dist[t.y] + 1) {
                dist[v] = dist[t.y] + 1;
                heap.push({f(v) + dist[v], v});
                pre[v] = {t.y, c[i]};
            }
            swap(v[pos], v[tran]);
        }
    }
    string ans;

    while (pre[ed].x != start) {
        ans += pre[ed].y;
        ed = pre[ed].x;
    }
    ans += pre[ed].y;
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    iosf;

    for (int i = 1; i <= 9; i++) {
        char c;
        cin >> c;
        start += c;
        if (c != 'x')
            list += c;
    }
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < i; j++) {
            if (list[j] > list[i])
                cnt++;
        }
    }
    if (cnt % 2)
        cout << "unsolvable" << endl;
    else
        cout << star(start) << endl;
}