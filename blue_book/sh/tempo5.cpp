#include <bits/stdc++.h>
#define pi pair<int, int>
#define X first
#define Y second
using namespace std;
typedef long long ll;
const int M = 300050, N = 504;
ll dp[M];
int day[M];
int d[N], k[N], c[N], cnt = 0;
int main()
{
    //freopen("r.txt","r",stdin);
    int n, m, r, p, q;
    scanf("%d %d %d", &n, &m, &r);
    for (int i = 1; i <= n; i++)
        scanf("%d %d %d", &d[i], &k[i], &c[i]);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &p, &q);
        for (int j = 1; j <= q; j++)
            day[++cnt] = p;
    }
    sort(day + 1, day + cnt + 1);
    //把每辆自行车的使用日期排序。这段时间一共使用了cnt辆自行车。
    for (int j = 1; j <= cnt; j++)
        dp[j] = 1ll * j * r;
    //dp[i][j]表示使用了前i种优惠券，用了前k辆自行车的价钱。
    //dp[0][j]数组初始化为什么优惠券都不使用时的价格，也就是dp[0][j]=j*r。其中dp[0][0]=0。
    for (int i = 1; i <= n; i++) {
        //dp[i][j]=min{dp[i][k]+c[i]}，其中k满足day[j]-day[k+1]+1<=d[i] and j-k<=k[i]。
        // and前面表示优惠券最多能用d[i]天，后面的则表示最多能花在k[i]辆车上。
        deque<int> q;
        q.push_back(0);
        for (int j = 1; j <= cnt; j++) {
            //这个dp用单调队列优化即可。
            while (!q.empty() && (j - q.front() > k[i] || day[j] - day[q.front() + 1] + 1 > d[i]))
                q.pop_front();
            dp[j] = min(dp[j], dp[q.front()] + c[i]);
            while (!q.empty() && dp[j] <= dp[q.back()])
                q.pop_back();
            q.push_back(j);
        }
    }
    printf("%lld\n", dp[cnt]); //dp[n][cnt]。
}
