/*
  Problem Name:搜索关键词
  algorithm tag:ac自动机，trie，kmp
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

const int N = 1e4 + 5, S = 55;
int n, root, idx;
string contents;

struct Node
{
    int son[26];
    int num;
    int nxt;
} trie[N * S];

void insert(string s)
{
    int now = root;
    for (int i = 0; i < s.size(); i++) {
        int j = s[i] - 'a';
        if (!trie[now].son[j])
            trie[now].son[j] = ++idx;
        now = trie[now].son[j];
    }
    trie[now].num++;
}
void build()
{
    queue<int> q;
    for (int i = 0; i < 26; i++)
        if (trie[root].son[i])
            q.push(trie[root].son[i]);

    while (q.size()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < 26; i++) {
            int v = trie[u].son[i];
            if (!v)
                continue;
            int j = trie[u].nxt;
            while (j && !trie[j].son[i])
                j = trie[j].nxt;
            if (trie[j].son[i])
                j = trie[j].son[i];
            trie[v].nxt = j;
            q.push(v);
        }
    }
}
int main()
{
    iosf;
    int _;
    cin >> _;
    while (_--) {
        cin >> n;
        memset(trie, 0, sizeof trie);
        idx = 0;
        for (int i = 1; i <= n; i++) {
            string s;
            cin >> s;
            insert(s);
        }
        build();

        cin >> contents;
        int res = 0;
        for (int i = 0, j = 0; i < contents.size(); i++) {
            int v = contents[i] - 'a';
            while (j && !trie[j].son[v])
                j = trie[j].nxt;
            if (trie[j].son[v])
                j = trie[j].son[v];
            int p = j;

            while (p) {
                res += trie[p].num;
                trie[p].num = 0;
                p = trie[p].nxt;
            }
        }
        cout << res << endl;
    }
    return 0;
}