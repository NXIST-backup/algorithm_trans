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

const int N = 5e3 + 4;

int dp[N];
pii a[N];
int n;

bool cmp(pii a,pii b){
    if(a.first<b.first)
        return true;
    else
        return false;
}


int main()
{
    cin >> n;

    for (int i = 1; i <= n;i++){
        int x, y;
        cin >> x >> y;
        a[i].first = x;
        a[i].second = y;
    }

    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n;i++){
        dp[i] = 1;
        for (int j = 1; j < i;j++){
            if(a[i].second>a[j].second)
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    int res = 0;
    for (int i = 1; i <= n;i++)
        res = max(res, dp[i]);

    cout << res << endl;
}