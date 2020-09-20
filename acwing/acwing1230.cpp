 //同余+前缀和

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
int n, k;
int a[N];
int ans[N];
int res = 0;
int main()
{
    cin >> n >> k;

    for (int i = 1; i <= n;i++){
        int x;
        cin >> x;
        a[i] = a[i - 1] + x;
    }

    for (int i = 1; i <= n;i++){
        res += ans[a[i] % k];
        ans[a[i] % k]++;
    }

    cout << res << endl;
}