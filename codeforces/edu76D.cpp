#include <cstdio>
#include<iostream>
#include<cstring>
using namespace std;
 
int t,n,m;
const int N=2e5+50;
int a[N];
int p[N];
 
 
int main()
{
    scanf("%d", &t);
    while(t--)
	{
        scanf("%d", &n);
        for(int i = 1;i <= n;i++)
			cin >> a[i];
        scanf("%d", &m);
        memset(p,-1,sizeof p);
		for(int i = 1;i <= m;i++)
		{
			int pi,si;
            scanf("%d%d", &pi, &si);
            p[si] = max(p[si],pi);
		}
		
		for(int i = n;i >= 1;i--)
		{
			p[i] = max(p[i],p[i+1]);
		}
 
        int idx = 1, ans = 0;
        while (idx<=n) {
            int cur = idx;
            int maxx = a[idx];
            //!从前端开始，
            //!首先坚持1天的英雄的最大能力值，是否大于第一个怪兽的能力值
            //!如果大于，j++，并取当前考虑过的怪兽的最大能力值，方便以后比较
            //!然后看第二天，如果能坚持两天的英雄的最大能力值，大于前两个怪兽的最大能力值
            //!接着往下考虑
            while (cur<=n&&p[cur-idx+1]>=maxx) {
                cur++;
                maxx = max(maxx, a[cur]);
            }
            if(cur==idx)//如果连最大的power都比不过当前怪物，输出-1
            {
                ans = -1;
                break;
            }
            ans++;
            idx = cur;
        }
        printf("%d\n", ans);
    }
}