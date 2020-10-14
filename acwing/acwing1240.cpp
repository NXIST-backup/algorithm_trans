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

const int N = 1e5 + 50;

int tr[N * 4];
int sum[40];
int n;

int log_2(int x)
{
    int res = 0;
    while(x){
        x >>= 1;
        res++;
    }
    return res;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> tr[i];

    for (int i = 1; i <= n;i++){
        sum[log_2(i)] += tr[i];
    }
    int ans = 1e9;
    ll res = -1e9;
    for (int i = 1; i <= 40; i++) {
        if(res==sum[i]){
            ans = min(ans, i);
        }
        else if(res<sum[i]){
            res = sum[i];
            ans = i;
        }
    }

    cout << ans << endl;
}
