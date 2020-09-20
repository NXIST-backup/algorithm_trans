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

const int X = 5050;
int n, r;
int g[X][X];
int main()
{
    cin >> n >> r;

    for (int i = 1; i <= n;i++){
        int x, y, w;
        cin >> x >> y >> w;
        g[x+1][y+1] = w;
    }
    int maxN = -1e9;
    for (int i = 1; i <= 5000;i++){
        for (int j = 1; j <= 5000;j++){
            g[i][j] = g[i][j - 1] + g[i - 1][j] - g[i - 1][j - 1]+g[i][j];
        }
    }
    for (int i = 5000; i >= r;i--){
        for (int j = 5000; j >=r ;j--){
            g[i][j] = g[i][j] - g[i - r][j] - g[i][j - r] + g[i - r][j - r];
            maxN = max(g[i][j], maxN);
        }
    }

    cout << maxN << endl;
}