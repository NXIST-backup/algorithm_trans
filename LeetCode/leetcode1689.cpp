/*
  Problem Name:十-二进制数的最少数目
  algorithm tag:高精度
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

int main()
{
    iosf;
    string s;
    cin >> s;
    int mx = 0;
    for (int i = 0; i < s.size(); i++) {
        mx = max(s[i] - '0', mx);
    }

    cout << mx << endl;
    return 0;
}