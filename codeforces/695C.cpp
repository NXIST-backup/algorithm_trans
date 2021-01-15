/*
   Problem Name:Three Bags
   algorithm tag:constructive program,greedy
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
const int mod = 1e9 + 7;
typedef pair<int, int> pii;

const int N = 3e5 + 5;
int n1, n2, n3;
ll max(ll a, ll b)
{
    if (a > b)
        return a;
    else
        return b;
}
int main()
{
    priority_queue<int, vector<int>, greater<int>> heap1, heap2, heap3, heap;

    cin >> n1 >> n2 >> n3;

    for (int i = 1; i <= n1; i++) {
        int x;
        cin >> x;
        heap1.push(x);
    }
    for (int i = 1; i <= n2; i++) {
        int x;
        cin >> x;
        heap2.push(x);
    }
    for (int i = 1; i <= n3; i++) {
        int x;
        cin >> x;
        heap3.push(x);
    }

    if (heap1.top() > heap2.top()) {
        heap = heap1;
        heap1 = heap2;
        heap2 = heap;
    }
    if (heap1.top() > heap3.top()) {
        heap = heap1;
        heap1 = heap3;
        heap3 = heap;
    }
    if (heap2.top() > heap3.top()) {
        heap = heap2;
        heap2 = heap3;
        heap3 = heap;
    }

    int min1 = heap1.top(), min2 = heap2.top(), min3 = heap3.top();
    heap1.pop();
    heap2.pop();
    heap3.pop();
    ll ans = 0;
    ll res = 0;
    ll trs = 0;
    while (heap1.size()) {
        res += heap1.top();
        heap1.pop();
    }
    while (heap2.size()) {
        ans += heap2.top();
        heap2.pop();
    }
    while (heap3.size()) {
        trs += heap3.top();
        heap3.pop();
    }

    ll t1 = ans + trs - min1;
    ll t2 = res + trs - min2;
    ll t3 = ans + res - min3;

    cout << max(max(t1 + abs(res - min2), t2 + abs(ans - min1)) + min3, t3 + abs(trs - min1) + min2) << endl;
}
