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

const int N = 1e6 + 50;
int n;
int a[N];
int c[N];

int main()
{
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n;i++){
        cin >> a[i];
        sum += a[i];
    }
    int avg = sum / n;
    c[n - 1] = a[n - 1] - avg;
    c[0] = 0;
    for (int i = n - 2; i >= 1;i--){
        c[i] = c[i + 1] + a[i] - avg;
    }
    sort(c, c + n);
    ll ans = 0;
    int mid = 0;
    if(n%2)
        mid = c[n / 2];
    else
        mid = c[n / 2 - 1] + c[n / 2] >> 1;
    for (int i = 0; i < n;i++){
        ans += abs(c[i] - mid);
    }
    cout<<ans<<endl;
}