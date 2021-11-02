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

const int N = 1e5 + 5;

struct Node
{
    int son[26];
    int cnt;
} trie[N];
int idx;

void insert(char str[])
{
    int now = 0;
    for (int i = 0; str[i]; i++) {
        int u = str[i] - 'a';
        if (!trie[now].son[u]) {
            trie[now].son[u] = ++idx;
            now = idx;
        } else
            now = trie[now].son[u];
    }
    trie[now].cnt++;
}
int query(char str[])
{
    int now = 0;
    for (int i = 0; str[i]; i++) {
        int u = str[i] - 'a';
        if (!trie[now].son[u])
            return 0;
        else
            now = trie[now].son[u];
    }

    return trie[now].cnt;
}

int main()
{
    insert("abc");
    insert("bas");
    insert("sdf");

    printf("%d\n", query("abc"));
    printf("%d\n", query("acd"));
}