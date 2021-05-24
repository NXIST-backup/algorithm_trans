/*
  Problem Name:普通平衡树
  algorithm tag:平衡树,Treap
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e8;
const int mod = 1e9 + 7;
const double eps = 1e-4;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
//#define x first
//#define y second
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

const int N = 1e5 + 5;
int n;
int root, idx;
struct Node
{
    int l, r;
    int key, val;
    int cnt, size;
} tr[N];

void pushup(int p)
{
    tr[p].size = tr[tr[p].l].size + tr[tr[p].r].size + tr[p].cnt;
}

int get_node(int key)
{
    tr[++idx].key = key;
    tr[idx].val = rand();
    tr[idx].cnt = tr[idx].size = 1;
    return idx;
}
void zig(int &p)
{
    int q = tr[p].l;
    tr[p].l = tr[q].r, tr[q].r = p, p = q;
    pushup(tr[p].r), pushup(p);
}
void zag(int &p)
{
    int q = tr[p].r;
    tr[p].r = tr[q].l, tr[q].l = p, p = q;
    pushup(tr[p].l), pushup(p);
}
void build()
{
    get_node(-INF), get_node(INF);
    root = 1, tr[1].r = 2;
    pushup(root);
    if (tr[1].val < tr[2].val)
        zag(root);
}
void insert(int &p, int key)
{
    if (!p)
        p = get_node(key);
    else if (tr[p].key == key)
        tr[p].cnt++;
    else if (tr[p].key > key) {
        insert(tr[p].l, key);
        if (tr[tr[p].l].val > tr[p].val)
            zig(p);
    } else {
        insert(tr[p].r, key);
        if (tr[tr[p].r].val > tr[p].val)
            zag(p);
    }
    pushup(p);
}
void remove(int &p, int key)
{
    if (!p)
        return;
    if (tr[p].key == key) {
        if (tr[p].cnt > 1)
            tr[p].cnt--;
        else if (tr[p].l || tr[p].r) {
            if (!tr[p].r || tr[tr[p].l].val > tr[tr[p].r].val) {
                zig(p);
                remove(tr[p].r, key);
            } else {
                zag(p);
                remove(tr[p].l, key);
            }
        } else
            p = 0;
    } else if (tr[p].key > key)
        remove(tr[p].l, key);
    else
        remove(tr[p].r, key);
    pushup(p);
}
int get_rank_by_key(int p, int key) // 通过数值找排名
{
    if (!p)
        return 0; // 本题中不会发生此情况
    if (tr[p].key == key)
        return tr[tr[p].l].size + 1;
    if (tr[p].key > key)
        return get_rank_by_key(tr[p].l, key);
    return tr[tr[p].l].size + tr[p].cnt + get_rank_by_key(tr[p].r, key);
}

int get_key_by_rank(int p, int rank) // 通过排名找数值
{
    if (!p)
        return INF; // 本题中不会发生此情况
    if (tr[tr[p].l].size >= rank)
        return get_key_by_rank(tr[p].l, rank);
    if (tr[tr[p].l].size + tr[p].cnt >= rank)
        return tr[p].key;
    return get_key_by_rank(tr[p].r, rank - tr[tr[p].l].size - tr[p].cnt);
}

int get_pre(int p, int key) // 找到严格小于key的最大数
{
    if (!p)
        return -INF;
    if (tr[p].key >= key)
        return get_pre(tr[p].l, key);
    return max(tr[p].key, get_pre(tr[p].r, key));
}

int get_suf(int p, int key) // 找到严格大于key的最小数
{
    if (!p)
        return INF;
    if (tr[p].key <= key)
        return get_suf(tr[p].r, key);
    return min(tr[p].key, get_suf(tr[p].l, key));
}
int main()
{
    build();
    iosf;
    cin >> n;
    while (n--) {
        int opt, x;
        cin >> opt >> x;
        if (opt == 1)
            insert(root, x);
        else if (opt == 2)
            remove(root, x);
        else if (opt == 3)
            cout << get_rank_by_key(root, x) - 1 << endl;
        else if (opt == 4)
            cout << get_key_by_rank(root, x + 1) << endl;
        else if (opt == 5)
            cout << get_pre(root, x) << endl;
        else
            cout << get_suf(root, x) << endl;
    }
}