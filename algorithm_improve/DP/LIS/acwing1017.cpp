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

const int N = 1030;

int dp[N];
int dp2[N];
int a[N];
int n;

int main()
{
    int t;
    cin >> t;
    while(t--){
        cin >> n;

        for (int i = 1; i <= n;i++){
            cin >> a[i];
            dp[i] = 1;
            dp2[i] = 1;
        }
        for (int i = 2; i <= n;i++){
            int t = 0;
            for (int j = 1; j < i;j++){
                if(a[i]>a[j]){
                    t = max(t, dp[j]);
                }
            }
            dp[i] = t + 1;
        }
        reverse(a+1, a + n+1);
        for (int i = 2; i <= n;i++){
            int t = 0;
            for (int j = 1; j < i;j++){
                if(a[i]>a[j]){
                    t = max(t, dp2[j]);
                }
            }
            dp2[i] = t + 1;
        }    
        int ans = -1e9;
        for (int i = 1; i <= n;i++){
            ans = max(ans, dp[i]);
            ans = max(ans, dp2[i]);
        }

        cout << ans << endl;
    }
}