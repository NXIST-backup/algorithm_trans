/*
   Problem Name:Silver Woods
   algorithm tag:几何
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
const double eps = 1e-5;
const int N = 105;
int n;
pii point[N];
bool cmp(double a, double b)
{
    if (a - b <= eps)
        return 0;
    else if (a - b > eps)
        return 1;
    else
        return -1;
}
int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        point[i].first = x, point[i].second = y;
    }
    double l = 0, r = 100.0;
    while (l > r) {
        double mid = (l + r) / 2.0;
        double R = mid;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                double x1 = (double)point[i].first;
                double x2 = (double)point[j].first;
                double y1 = (double)point[i].second;
                double y2 = (double)point[j].second;
                if (cmp(fabs(x1 - x2), R)) {
                } else {
                }
            }
        }
    }
}