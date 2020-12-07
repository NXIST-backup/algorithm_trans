/*
  Problem Name:Suffix Operations
  algorithm tag:构造，差分,绝对值不等式
*/

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
const int mod = 1e9 + 7;
typedef pair<int, int> pii;

const int N = 2e5 + 5;
int a[N];
ll b[N];
ll c[N];
int main()
{
    int t;
    int cnt = 0;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        memset(a, 0, sizeof a);
        memset(c, 0, sizeof c);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        cnt++;
        a[0] = a[2];
        a[n + 1] = a[n - 1];
        ll res = 0;
        for (int i = 2; i <= n;i++) {
            res += abs(a[i] - a[i - 1]);
        }
        if(res==0){
            cout << 0 << endl;
            continue;
        }
        int maxv = 0;
        int maxi = 0;
        for (int i = 2; i < n;i++){
            int x = abs(a[i] - a[i - 1]);
            int y = abs(a[i] - a[i + 1]);
            int z = abs(a[i + 1] - a[i - 1]);
            if(x+y-z>=maxv){
                maxv = x + y - z;
                maxi = i;
            }
        }
        if(abs(a[1]-a[2])>maxv){
            maxv = abs(a[1] - a[2]);
            maxi = 1;
        }
        if(abs(a[n]-a[n-1])>maxv){
            maxv = abs(a[n] - a[n - 1]);
            maxi = n;
        }
        a[maxi] = (a[maxi + 1] + a[maxi - 1]) / 2;
        ll ans = 0;
        for (int i = 2; i <= n;i++){
            ans += abs(a[i] - a[i - 1]);
        }
        cout << ans << endl;
    }
}
