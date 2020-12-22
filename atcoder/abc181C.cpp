/*
  Problem Name:Collinearity
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
const int mod = 1e9 + 7;
typedef pair<int, int> pii;

const int N = 105;
int n;
pii a[N];

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        a[i].first = x;
        a[i].second = y;
    }
    bool is_valid = false;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            for (int k = j + 1; k <= n; k++) {
                int x1 = a[i].first, y1 = a[i].second;
                int x2 = a[j].first, y2 = a[j].second;
                int x3 = a[k].first, y3 = a[k].second;
                if ((x3 - x2) * (y1 - y2) == (x1 - x2) * (y3 - y2))
                    is_valid = true;
            }
        }
    }
    if (is_valid)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}