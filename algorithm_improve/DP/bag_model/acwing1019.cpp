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

const int N = 5050, M = 6005;
int v[N];
int w[N];
int n, m;
int dp[M];
int idx;

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n;i++){
        int a, b, s;
        cin >> a >> b >> s;

        while(s--){
            v[++idx] = a;
            w[idx] = b;
        }
    }

    for (int i = 1; i <= idx;i++){
        for (int j = m; j >= v[i];j--)
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
    }

    cout << dp[m] << endl;
}