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

int t;
int a[5050][2];
int st[5050];

int main()
{
    cin >> t;

    while (t--) {

        int n;

        cin >> n;
        memset(st, 0, sizeof st);
        memset(a, 0, sizeof a);
        for (int i = 1; i <= n;i++)
            a[i][1] = 1e9;
        for (int i = 0; i < n;i++)
        {
            int x;
            cin >> x;
            st[x]++;
            if(i>a[x][0])
                a[x][0] = i;
            if(i<a[x][1])
                a[x][1] = i;
        }
        int flag = 0;
        for (int i = 1; i <= n;i++)
        {
            if(st[i]>=2)
            {
                if(a[i][0]-a[i][1]>=2)
                {
                    flag = 1;
                    break;
                }
            }
        }
        if(flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}