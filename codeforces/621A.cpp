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
int n,d;
int a[150];

int main()
{
    cin >> t;
    while (t--) {
        cin >> n >> d;

        for (int i = 1; i <= n;i++)
        {
            cin >> a[i];
        }
        int sum = a[1];
        for (int i = 2; i <= n;i++)
        {
            if(d-a[i]*(i-1)>=0)
            {
                d -= a[i] * (i - 1);
                sum += a[i];
            }
            else
            {
                d /= (i - 1);
                sum += d;
                break;
            }
        }
        cout << sum << endl;
    }
}