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

const int N = 5e4 + 5;
int n, idx, root;
string s[N];
struct Node
{
    int son[28];
    int fa;
    int num;
    bool tag;
} trie[N];

int del(char a)
{
    if (a == '.')
        return 27;
    else if (a == '/')
        return 28;
    else
        return a - 'a';
}
void insert(string s)
{
    int now = root;
    for (int i = 0; i < s.size(); i++) {
        int j = del(s[i]);
        if (!trie[now].son[j]) {
            trie[now].son[j] = ++idx;
            trie[idx].fa = now;
        }
        now = trie[now].son[j];
    }
    trie[now].num++;
}
int update(string s)
{
    int now = root;
    for (int i = 0; i < s.size(); i++) {
        int j = del(s[i]);
        now = trie[now].son[j];
    }
    trie[now].tag = 1;

    while (now != root) {
        int fa = trie[now].fa;
        int res = 0;
        bool flag = 0;
        for (int i = 0; i < 28; i++) {
            int j = trie[fa].son[i];
            res += trie[j].num;
            if (trie[j].tag != 1) {
                flag = 1;
                break;
            }
        }
        if (!flag)
            trie[fa].num = 1;
        else
            trie[fa].num = res;
    }
    return trie[root].num;
}

int main()
{
    iosf;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        insert(s[i]);
    }
    trie[root].fa = -1;
    for (int i = 1; i <= n; i++) {
        int res = update(s[i]);
        cout << res << endl;
    }
}