//排队打水

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
typedef pair<int, int> pii;

const int N = 1e5 + 5;
int n;
ll a[N];
int main()
{
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
    ll res = 0;
    sort(a,a+n);
    for (int i = 0; i < n - 1; i++)
        res += a[i], a[i] = res;
    res = 0;
    for (int i = 0; i < n - 1; i++)
        res += a[i];
    cout << res << endl;

}
    