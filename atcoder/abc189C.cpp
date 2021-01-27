/*
  Problem Name:Mandarin Orange
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
typedef pair<int, int> pii;

const int N = 1e4 + 5;
int a[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int mn = a[i];
        int res = 0;
        for (int j = 1; j <= n; j++) {
            if (a[j] >= mn)
                res += mn;
            else if (j < i)
                res = 0;
            else
                break;
        }
        ans = max(ans, res);
    }

    cout << ans << endl;
}