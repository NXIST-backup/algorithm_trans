/*
  Problem Name:Building a Fence
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

const int N = 2e5 + 5;
int t;
int h[N];
int n, k;
int main()
{
    cin >> t;
    while (t--) {
        cin >> n >> k;
        bool is_valid = true;
        for (int i = 1; i <= n; i++)
            cin >> h[i];
        int l = h[1], r = h[1];
        for (int i = 2; i <= n; i++) {
            l = max(h[i], l - k + 1);
            r = min(h[i] + k - 1, r + k - 1);
            if (l > r) {
                is_valid = false;
                break;
            }
        }
        if (h[n] > r || h[n] < l)
            is_valid = false;

        if (is_valid)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}