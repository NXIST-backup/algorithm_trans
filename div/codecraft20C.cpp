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

const int N = 2e6 + 50;

int n, m, p;

int main()
{
    scanf("%d%d%d", &n, &m, &p);
    int res = 0;
    int flag = 0;
    for (int i = 0; i < n;i++)
    {
        int x;
        scanf("%d", &x);

        if(x%p!=0&&!flag)
        {
            res = i;
            flag = 1;
        }
    }
    flag = 0;
    for (int i = 0; i < m;i++)
    {
        int x;
        scanf("%d", &x);

        if (x % p != 0 && !flag)
        {
            res += i;
            flag = 1;
        }
    }

    cout << res << endl;
}