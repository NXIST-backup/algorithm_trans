/*
  Problem Name:Odd Divisor
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

int t;
ll n;

int main()
{
    cin >> t;
    while (t--) {
        cin >> n;

        while (n % 2 == 0) {
            n >>= 1;
        }

        if (n == 1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}