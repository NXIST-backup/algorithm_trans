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

const int N = 1e5 + 50;
int t;
int n, x;
int a[N];

int main()
{
    cin >> t;


    while (t--) {

        cin >> n >> x;

        for (int i = 0; i < n;i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        if(a[n-1]>x)
        {

            int flag = 1;
            for (int i = 0; i < n;i++)
            {
                if(a[i]==x)
                {
                    flag = 0;
                    cout << 1 << endl;
                }
            }
            if(flag)
                cout << 2 << endl;
        }
        else if(x%a[n-1])
            cout << x / a[n-1] + 1 << endl;
        else 
            cout << x / a[n-1] << endl;
    }
}