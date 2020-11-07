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

const int N = 1050;

int m, n;
int a[N][N], b[N][N];
int dp[N][N];

int main()
{
    cin >> m >> n;

    for (int i = 1; i <= n;i++){
        int x, y, z;
        cin >> x >> y >> z;
        a[z][i] = x;
        b[z][i] = y;
    }

    for(int )

}