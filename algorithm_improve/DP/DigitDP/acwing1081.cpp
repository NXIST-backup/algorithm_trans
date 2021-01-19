/*
  Problem Name:度的数量
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
int K, B;
void Init()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++)
            if (!j)
                f[i][j] = 1;
            else
                f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
}

int dp(int n)
{
    if (!n)
        return 0;
    vector<int> nums;

    while (n) {
        nums.push_back(n % B);
        n /= B;
    }

    int res = 0;
    int last = 0;

    for (int i = nums.size() - 1; i >= 0; i--) {
        int t = nums[i];
        if (t) {
            if (t > 1) {
                res += f[i][K - last];
                if (K - last - 1 >= 0)
                    res += f[i][K - last - 1];
                break;
            } else {
                res += f[i][K - last];
                last++;
                if (last > K)
                    break;
            }
        }
        if (!i && last == K) {
            res++;
        }
    }
    return res;
}

int main()
{
    cin >> l >> r >> K >> B;
    Init();
    cout << dp(r) - dp(l - 1) << endl;
}