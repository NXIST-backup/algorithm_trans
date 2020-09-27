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

int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed;

    cin >> n;

    vector<int> a(n);

    for (int i = 0;i<n;i++)
        cin >> a[i];
    ll res = 0;
    for (int i = 0; i < n; i++) {
        int mx = -1e9, mn = +1e9;

        for(int j=i;j<n;j++){
            mx = max(mx, a[j]);
            mn = min(mn, a[j]);
            if(mx-mn==j-i)
                res++;
        }
    }

    cout << res << endl;
}