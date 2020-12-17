/*
  Problem Name:
  algorithm tag:模拟
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

string s;

int main()
{
    cin >> s;
    int n = s.size();
    int sum = 0;
    for (int i = 0; i < s.size(); i++) {
        sum += s[i] - '0';
    }
    int ans = 1e9;
    bool is_valid = false;
    int cnt = 0;
    for (int i = 0; i < 1 << n; i++) {
        int tmp = sum;
        cnt = 0;
        for (int j = 0; j < n; j++) {
            if (i >> j & 1) {
                tmp -= s[j] - '0';
                cnt++;
            }
        }
        if (tmp % 3 == 0 && tmp != 0) {
            is_valid = true;
            ans = min(ans, cnt);
        }
    }
    if (is_valid)
        cout << ans << endl;
    else
        cout << -1 << endl;
}