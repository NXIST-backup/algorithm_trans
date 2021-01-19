/*
  Problem Name:数字游戏 
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

const int N = 35;

int f[N][N];
int l, r;

void init()
{
    for (int i = 1; i < N; i++)
        f[1][i] = 1;

    for (int i = 2; i < N; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = j; k <= 9; k++)
                f[i][j] += f[i - 1][k];
        }
    }
}
int dp(int n)
{
    if (!n)
        return 0;
    vector<int> nums;
    while (n) {
        nums.push_back(n % 10);
        n /= 10;
    }
    int res = 0;
    int last = 0;
    bool flag = true;
    for (int i = nums.size() - 1; i >= 0; i--) {
        int t = nums[i];
        if (t < last) {
            flag = 0;
            break;
        }
        for (int j = last; j < t; j++)
            res += f[i + 1][j];
        last = t;
    }
    if (flag)
        res++;
    return res;
}

int main()
{
    init();
    while (cin >> l >> r) {
        dp(r);
        cout << dp(r) - dp(l - 1) << endl;
    }
}