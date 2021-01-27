/*
  Problem Name:New Year's Number
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
int n;

int main()
{
    cin >> t;

    while (t--) {
        cin >> n;

        int nums = n / 2020;
        int res = n % 2020;
        if (nums >= res)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}