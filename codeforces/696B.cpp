/*
  Problem Name:Different Divisors
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

const int N = 30005;
int t;
int d;
bool prime[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed;
    cin >> t;

    for (int i = 2; i < N; i++) {
        bool flag = 1;
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                flag = false;
                break;
            }
        }
        if (flag)
            prime[i] = 1;
    }

    while (t--) {
        cin >> d;

        if (d == 1) {
            cout << 6 << endl;
            continue;
        }
        ll a = 0, b = 0;
        int idx = 1 + d;
        while (!prime[idx])
            idx++;
        a = idx;
        idx += d;

        while (!prime[idx])
            idx++;
        b = idx;
        cout << a * b << endl;
    }
}