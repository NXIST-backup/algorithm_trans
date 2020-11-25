//混合背包

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

const int N = 11005, M = 1005;
int n, m;
int w[N], v[N];
int dp[M];
int idx;

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n;i++){
        int a, b, s;
        cin >> a >> b >> s;
        int k = 1;
        if(s==-1){
            idx++;
            v[idx] = a;
            w[idx] = b;
            continue;
        }
        if(s==0){
            int tmp = 1000;
            while(k<=tmp){
                idx++;
                v[idx] = a * k;
                w[idx] = b * k;
                tmp -= k;
                k *= 2;
            }
            if(tmp>0){
                idx++;
                v[idx] = tmp * a;
                w[idx] = tmp * b;
            }            
        }
        else{
            while(k<=s){
                idx++;
                v[idx] = a * k;
                w[idx] = b * k;
                s -= k;
                k *= 2;
            }
            if(s>0){
                idx++;
                v[idx] = s * a;
                w[idx] = s * b;
            }      
        }
    }

    for (int i = 1; i <= idx;i++){
        for (int j = m; j >= v[i];j--)
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
    }

    cout << dp[m] << endl;
}
