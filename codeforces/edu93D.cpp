//三维DP

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

const int N = 250;
int r, g, b;
vector<int> R, G, B;

bool cmp(int a,int b){
    return a > b;
}
int dp[N][N][N];

int main()
{
    cin >> r >> g >> b;

    for (int i = 0; i < r;i++){
        int x;
        cin >> x;
        R.push_back(x);
    }
    for (int i = 0; i < g;i++){
        int x;
        cin >> x;
        G.push_back(x);
    }
    for (int i = 0; i < b;i++){
        int x;
        cin >> x;
        B.push_back(x);
    }

    sort(R.begin(),R.end());
    sort(G.begin(),G.end());
    sort(B.begin(),B.end());

    for (int i = 0; i <= r;i++){
        for (int j = 0; j <= g;j++){
            for (int k = 0; k <= b;k++){
                if(i&&j)
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + R[i - 1] * G[j - 1]);
                if(i&&k)
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + R[i - 1] * B[k - 1]);
                if(j&&k)
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1] + B[k - 1] * G[j - 1]);                
            }
        }
    }

    cout << dp[r][g][b] << endl;
}