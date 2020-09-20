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

int t;
ll a, b, x, y, n;


int main()
{
    cin >> t;

    while (t--) {
        cin >> a >> b >> x >> y >> n;

        ll sum1 = 0, sum2 = 0;
        if(n>(a-x)+(b-y))
            cout << x * y << endl;
        else{
            int a1 = a, b1 = b, x1 = x, y1 = y, n1 = n;

            int temp = b;
            b = max(y, b - n);
            n -= temp - b;
            a = max(x, a - n);
            sum1 = (ll)a * (ll)b;
            a = a1, b = b1, x = x1, y = y1, n = n1;
            temp = a;
            a = max(x, a - n);
            n -= temp - a;
            b = max(y, b - n);
            sum2 = (ll)a * (ll)b;

            if(sum1>sum2)
                cout << sum2 << endl;
            else
                cout << sum1 << endl;
        }
    }
}