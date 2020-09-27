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

int n;
int a[N], b[N], c[N];
int pre[N],pre2[N];
int main()
{
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> a[i];
        pre2[a[i]]++;
    }

    for (int i = 0; i < n; i++)
        cin >> b[i];

    for (int i = 0; i < n; i++){
        cin >> c[i];
        pre[c[i]]++;
    }

    for (int i = 1; i <= N;i++){
        pre2[i] += pre2[i - 1];
        pre[i] += pre[i - 1];
    }

    ll ans = 0;

    for (int i = 0; i < n;i++){
        ans += (pre[N] - pre[b[i]]) * pre2[b[i] - 1];
    }

    cout << ans << endl;
}