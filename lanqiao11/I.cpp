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

const int N = 1e5 + 50;
ll n, k, ans;
vector<ll> a;
int st[N][11];

int length(ll x)
{
    int cnt = 0;
    while(x){
        x /= 10;
        cnt++;
    }
    return cnt;
}
void check()
{
    for (int i = 0; i < n; i++) {
        int len = length(a[i]);
        ans += st[(k - a[i] % k) % k][len];
        ll p = 1;
        for (int j = 0; j <= 10;j++){//1e9是10位 千万注意
            st[((a[i]%k) * p) % k][j]++;
            p = p * 10 % k;
        }
    }
}

int main()
{
    cin >> n >> k;

    for (int i = 0; i < n;i++){
        int x;
        cin >> x;
        a.push_back(x);
    }

    check();

    memset(st, 0, sizeof st);
    reverse(a.begin(), a.end());
    check();

    cout << ans << endl;
}