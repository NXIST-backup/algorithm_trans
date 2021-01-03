//普通模拟题

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

typedef long long  ll;
int t;
int n, k;
ll a[35];
bool st[60];
int main()
{
    cin >> t;

    while (t--) {

        cin >> n >> k;

        for (int i = 0; i < n;i++)
            cin >> a[i];

        sort(a, a + n);
        int flag = 1;
        int mm = 0;
        memset(st, 0, sizeof st);
        for (int i = 0; i < n;i++)
        {
            if(a[i]!=0)
            {
                int t;
                int cnt = 0;
                while (a[i]) {
                    t = a[i] % k;
                    if(t==1&&!st[cnt])
                    {
                        st[cnt] = 1;
                        a[i]--;
                    }
                    else if(t==1&&st[cnt])
                    {
                        flag = 0;
                        break;
                    }
                    else if(t>1)
                    {
                        flag = 0;
                        break;
                    }
                    a[i] /= k;
                    cnt++;
                }
            }
            if(!flag)
                break;
        }
        // for (int i = 0; i < 35;i++)
        // {
        //     cout << st[i] << " ";
        // }
        // puts("");

        if(!flag)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}