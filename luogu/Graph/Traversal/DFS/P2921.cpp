#include "iostream"
#include "cstdio"

using namespace std;
const int N=1e6+50;

int n, d[N], s[N], h[N], flag;

bool vis[N];

int dfs(int now,int nows)
{
    if(h[now]!=0)
        return nows - 1 + h[now];
    if(vis[now]==true)
    {
        h[now] = nows - s[now];
        flag = now;
        return nows - 1;
    }
    vis[now] = true;
    s[now] = nows;
    int ans = dfs(d[now], nows + 1);

    if(flag!=0)
    {
        if(now==flag)
            flag = 0;
        else
            h[now] = h[flag];
    }
    else
        h[now] = h[d[now]] + 1;
    vis[now] = false;
    return ans;
}


int main()
{
    cin >> n;

    for (int i = 1; i <= n;i++)
        cin >> d[i];

    for (int i = 1; i <= n;i++)
        cout << dfs(i, 1) << endl;
    
}