/*
  Problem Name:铲雪车
  algorithm tag:欧拉回路
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

int main()
{
    double x1, y1, x2, y2;
    cin >> x1 >> y1;
    double sum = 0;
    while (cin >> x1 >> y1 >> x2 >> y2) {
        double len = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) * 2;
        sum += len;
    }
    int ans = round(sum / 1000 * 3);
    printf("%d:%02d\n", ans / 60, ans % 60);
}