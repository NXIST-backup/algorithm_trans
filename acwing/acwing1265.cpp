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

typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e9;
typedef pair<int,int> pii;
//!注意0，0的情况

const int N = 40050;
int n;
int c[N];
int a[N];
int sum[N];
int lowbit(int x)
{
    return x & -x;
}
void add(int x,int v)
{
    for (int i = x; i <= N;i+=lowbit(i))
        c[i] += v;
}

int query(int x)
{
    int res = 0;
    for (int i = x; i;i-=lowbit(i))
        res += c[i];
    return res;
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n;i++){
        int x, y;
        cin >> x >> y;
        a[i] = x + 1;
    }

    for (int i = 1; i <= n;i++){
        sum[query(a[i])]++;
        add(a[i], 1);
    }

    for (int i = 0; i <= n-1;i++)
        cout << sum[i] << endl;
    
}