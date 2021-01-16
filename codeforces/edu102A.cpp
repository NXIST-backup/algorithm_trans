/*
  Problem Name:Replacing Elements
  algorithm tag:easy 
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

int t;
int n, d;

int main()
{
    cin >> t;

    while (t--) {
        cin >> n >> d;

        int m1 = mod, m2 = mod;
        bool flag = false;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            if (x > d)
                flag = true;
            if (m1 > x) {
                m2 = m1;
                m1 = x;
            } else if (m2 > x) {
                m2 = x;
            }
        }
        if (!flag) {
            cout << "YES" << endl;
            continue;
        }
        if (m1 + m2 <= d)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}