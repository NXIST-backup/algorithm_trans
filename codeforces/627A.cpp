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
int a[150];

int main()
{
    cin >> t;

    while (t--) {

        int n;

        cin >> n;

        for (int i = 1; i <= n;i++)
        {
            cin >> a[i];
        }

        if(n==1)
            cout << "YES" << endl;

        else
        {
            int flag = 1;
            for (int i = 1; i <= n;i++)
            {
                for (int j = 1; j <= n;j++)
                {
                    if((a[i]-a[j])%2!=0)
                    {
                        flag = 0;
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
}