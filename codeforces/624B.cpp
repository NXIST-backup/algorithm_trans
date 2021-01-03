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

const int N = 150;

int t;

int n, m;

int a[N], p[N];

int main()
{
    cin >> t;

    while (t--) {

        cin >> n >> m;
        memset(a, 0, sizeof a);
        memset(p, 0, sizeof p);
        for (int i = 1; i <= n;i++)
            cin >> a[i];

        for (int i = 1; i <= m;i++)
        {
            int x;
            cin >> x;
            p[x]=1;
        }
        int flag = 1;
        for (int i = 1; i <= n;i++)
        {
            for (int j = 1; j <= n-i;j++)
            {
                if(a[j]>a[j+1])
                {
                    if(p[j])
                        swap(a[j], a[j + 1]);
                    else
                    {
                        flag = 0;
                        break;
                    }
                }
            }
            if(flag==0)
                break;
        }
        if(flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}