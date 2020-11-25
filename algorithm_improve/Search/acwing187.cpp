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

const int N = 55;
int n;
int a[N];
int up[N], down[N];
int ans;

void dfs(int dep,int su,int sd)
{
    if(su+sd>=ans)
        return;
    if(dep==n){
        ans = su + sd;
        return;
    }
    //上升
    int k = 0;
    while(k<su&&up[k]>=a[dep])//挑出来的序列一定是严格不下降的(可以用二分优化)
        k++;
    int t = up[k];
    up[k] = a[dep];
    if(k<su)
        dfs(dep + 1, su, sd);
    else
        dfs(dep + 1, su + 1, sd);
    up[k] = t;
    //下降

    k = 0;
    while(k<su&&up[k]<=a[dep])
        k++;
    t = down[k];
    up[k] = a[dep];
    if(k<su)
        dfs(dep + 1, su, sd);
    else
        dfs(dep + 1, su, sd + 1);
    down[k] = t;
}

int main()
{
    while(cin>>n,n){
        for (int i = 1; i <= n;i++)
            cin >> a[i];

        dfs(0, 0, 0);

        cout << ans << endl;
    }
}