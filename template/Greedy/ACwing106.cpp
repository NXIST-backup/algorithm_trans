//货仓选址

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <stdlib.h>
#include <unordered_map>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e9;
typedef pair<int, int> pii;
const int N=1e6+50;
int n;
int a[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int ans=0;
    if (n % 2) {
        int mid = a[n / 2];
        for (int i = 0; i < n; i++)
            ans += abs(a[i] - mid);
    }else {
        int mid = (a[n / 2] + a[n / 2 - 1]) / 2;
        for (int i = 0; i < n; i++)
            ans+=abs(a[i]-mid);
    }
    cout << ans << endl;
}