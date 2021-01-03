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

const int N = 1e5 + 5;
int t;
int n;
ll a[N];

int main()
{
    cin >> t;

    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        ll cnt = 0;
        sort(a + 1, a + 1 + n);
        for (int i = 2; i <= n; i++)
            cnt += a[n] - a[i];
        if (a[1] > cnt) {
            ll tmp = a[1] - cnt;
            ll ans = 0;
            if(tmp%(n-1))
                ans += (n - 1) - tmp % (n - 1);
            cout << ans << endl;
        } else
            cout << cnt-a[1] << endl;
    }
}