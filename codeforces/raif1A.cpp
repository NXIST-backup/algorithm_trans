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

int main()
{
    cin >> t;
    while(t--){
        ll ans = 0;
        int x1, y1, x2, y2;

        cin >> x1 >> y1 >> x2 >> y2;

        if(abs(x2-x1)&&abs(y2-y1)){
            ans += 2;
        }
        ans += abs(x2 - x1);
        ans += abs(y2 - y1);
        cout << ans << endl;
    }
}