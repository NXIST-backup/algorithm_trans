/*
  Problem Name:
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

int n;

int main()
{
    cin >> n;

    vector<int> a;
    pii ans1 = {0, 0}, ans2 = {0, 0};
    for (int i = 0; i < 1 << n; i++) {
        int x;
        cin >> x;
        if (i < ((1 << n) / 2)) {
            if (ans1.first < x) {
                ans1.first = x;
                ans1.second = i;
            }
        } else {
            if (ans2.first < x) {
                ans2.first = x;
                ans2.second = i;
            }
        }
    }
    if (ans1.first > ans2.first)
        cout << ans2.second + 1 << endl;
    else
        cout << ans1.second + 1 << endl;
}