/*
  Problem Name:Planet Lapituletti
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
const int INF = 1e9;
const int mod = 1e9 + 7;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

int t;
int st[10];
int h, m;
int hour, minut;
int st2[10];

int del(string s)
{
    int res = 0;
    int p = 10;
    for (int i = 0; i < 2; i++)
        res += p * (s[i] - '0'), p /= 10;
    return res;
}
bool check()
{
    int n1 = hour / 10, n2 = hour % 10, n3 = minut / 10, n4 = minut % 10;

    if (!st[n1] || !st[n2] || !st[n3] || !st[n4])
        return false;

    n1 = st2[n1];
    n2 = st2[n2];
    n3 = st2[n3];
    n4 = st2[n4];

    if (n4 * 10 + n3 < h && n2 * 10 + n1 < m)
        return true;
    else
        return false;
}
void add()
{
    minut++;
    if (minut >= m) {
        hour++;
        minut = 0;
    }
    if (hour >= h) {
        hour = 0;
        minut = 0;
    }
}
int main()
{
    cin >> t;
    st[0] = st[1] = st[2] = st[5] = st[8] = 1;
    st2[2] = 5;
    st2[5] = 2;
    st2[0] = 0;
    st2[1] = 1;
    st2[8] = 8;
    while (t--) {
        cin >> h >> m;
        string time;
        cin >> time;

        hour = del(time.substr(0, 2));
        minut = del(time.substr(3, 4));

        while (!check())
            add();
        if (hour < 10)
            cout << 0;
        cout << hour << ":";
        if (minut < 10)
            cout << 0;
        cout << minut << endl;
    }
}