#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e9;
typedef pair<int,int> pii;

const int N = 1e3 + 5;
int n;
int dp[N];
int a[5] = {0, 10, 20, 50, 100};
int main()
{
    cin >> n;
    dp[0] = 1;
    for (int i = 1; i <= 4;i++){
        for (int j = n; j >= 0;j--){
            for (int k = 1; k * a[i] <= j;k++){
                dp[j] += dp[j - k * a[i]];
            }
        }
    }

    cout << dp[n] << endl;
}