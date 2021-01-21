/*
  Problem Name:不要62
  algorithm tag:数位DP
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
#define vec vector

const int N = 35;

ll f[N][N];
int l, r;

void init()
{
    for (int i = 0; i <= 9; i++)
        if (i != 4)
            f[1][i] = 1;

    for (int i = 2; i < N; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= 9; k++) {
                if (j == 6 && k == 2)
                    continue;
                if (j == 4 || k == 4)
                    continue;
                f[i][j] += f[i - 1][k];
            }
        }
    }
}
ll dp(int n)
{
    if (!n)
        return 1;
    vec<int> nums;

    while (n)
        nums.push_back(n % 10), n /= 10;
    int res = 0;
    int last = 0;
    bool flag = true;
    for (int i = nums.size() - 1; i >= 0; i--) {
        int t = nums[i];

        for (int j = 0; j < t; j++) {
            if ((last == 6 && j == 2) || j == 4)
                continue;
            res += f[i + 1][j];
        }
        if ((last == 6 && t == 2) || t == 4) {
            flag = false;
            break;
        }
        last = t;
    }
    if (flag)
        res++;
    return res;
}

int main()
{
    init();
    while (cin >> l >> r, l && r) {
        cout << dp(r) - dp(l - 1) << endl;
    }
}