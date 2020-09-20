#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <stdio.h>
#include <unordered_map>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e9;
typedef pair<int,int> pii;

int n, m, k;


int main()
{
    cin >> n >> m >> k;

    for (int i = 0; i < k*2;i++)
    {
        int x, y;
        cin >> x >> y;
    }

    cout << (n - 1) + (m - 1) + (n * m)-1 << endl;

    for (int i = 0; i < n - 1;i++)
        cout << "U";
    for (int i = 0; i < m - 1;i++)
        cout << "L";
    for (int i = 1; i <= n;i++)
    {
        for (int j = 0; j < m - 1;j++)
            if(i%2)
                cout << "R";
            else
                cout << "L";
        if(i!=n)
            cout << "D";
    }
    puts("");
}