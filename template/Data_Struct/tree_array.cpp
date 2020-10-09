#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e9;
typedef pair<int, int> pii;

const int N = 1e5 + 50;

int n, m;
int a[N], tr[N];

int lowbit(int x)
{
    return x & -x;
}
void add(int x, int v)
{
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += v;
}
int query(int x)
{
    int res = 0;
    for (int i = x; i ;i-=lowbit(i))
        res += tr[i];
    return res;
}
int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
        add(i, a[i]);


    while (m--){
        int k, x, y;

        cin >> k >> x >> y;

        if(k==0)
            cout << query(y) - query(x - 1) << endl;
        else
            add(x, y);
    }
    
}