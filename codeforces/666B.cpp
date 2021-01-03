#include <iostream>
#include <cstring>
#include <algorithm>
#include <math.h>
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
int n;
ll a[N];
int bs(int l,int r,int k)
{
    if(l>=r)
        return l;
    int mid = (l + r) >> 1;
    if(pow(mid,n-1)==k)
        return mid;
    if(pow(mid, n-1)>k)
        return bs(l, mid, k);
    if(pow(mid,n-1)<k)
        return bs(mid + 1, r, k);

}

int main()
{
    cin >> n;
    for (int i = 0; i < n;i++)
        cin >> a[i];
    sort(a, a + n);
    double trans = n;
    double strat = pow(1e9, 1 / (trans - 1));
    int strat2 = strat;
    int t = bs(1, strat2, a[n - 1]);
    ll sum = 0;
    ll sum2 = 0;
    ll temp = 1;
    for (int i = 0; i < n;i++){
        sum += abs(a[i] - temp);
        temp *= t;
    }
    temp = 1;
    t += 1;
    for (int i = 0; i < n;i++){
        sum2 += abs(a[i] - temp);
        if(temp>=1e18)
            temp = 1e11;
        else
            temp *= t;
    }
    if(t>=3){
        temp = 1;
        ll sum3 = 0;
        t -= 2;
        for (int i = 0; i < n;i++){
            sum3 += abs(a[i] - temp);
            temp *= t;
        }
        cout << min(sum3, min(sum, sum2)) << endl;


    }
    else {    
        if(sum2<sum&&sum2>=0)
            cout << sum2 << endl;
        else
            cout << sum << endl;
    }
}