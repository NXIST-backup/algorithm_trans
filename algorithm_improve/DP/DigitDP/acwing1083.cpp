/*
  Problem Name:Windy数
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

const int N = 30;
int f[N][N];
int l, r;

void init()
{
    for (int i = 0; i <= 9; i++)
        f[1][i] = 1;
    for (int i = 2; i < N; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= 9; k++)
                if (abs(j - k) >= 2)
                    f[i][j] += f[i - 1][k];
        }
    }
}
int dp(int n)
{
    if (!n)
        return 0;

    vector<int> nums;

    while (n)
        nums.push_back(n % 10), n /= 10;
    int res = 0;
    int last = -2;
    bool flag = 1;
    for (int i = nums.size() - 1; i >= 0; i--) {
        int t = nums[i];

        if (t) {
            for (int j = i == nums.size() - 1; j < t; j++)
                if (abs(j - last) >= 2)
                    res += f[i + 1][j];
        }
        if (abs(t - last) < 2) {
            flag = 0;
            break;
        }
        last = t;
    }
    if (flag)
        res++;
    for (int i = 1; i <= nums.size() - 1; i++) {
        for (int j = 1; j <= 9; j++)
            res += f[i][j];
    }
    return res;
}

int main()
{
    init();
    cin >> l >> r;
    cout << dp(r) - dp(l - 1) << endl;
}