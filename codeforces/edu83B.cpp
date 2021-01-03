//拿来出题

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <stdio.h>
#include <unordered_map>
#include <cmath>
#include <cstdio>
#include <utility>
#include <vector>

using namespace std;

const int N = 150;

int t;
int n;
int a[N];

bool cmp(const int a,const int b)
{
    return a > b;
}
int main()
{
    cin >> t;

    while (t--) {

        cin >> n;
        for (int i = 1; i <= n;i++)
        {
            cin >> a[i];
        }

        sort(a + 1, a + n + 1,cmp);

        for (int i = 1; i <= n;i++)
            cout << a[i] << " ";
        puts("");
    }
}