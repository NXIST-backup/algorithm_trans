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

int main()
{
    int n;
    cin >> n;
    int path = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        path++;
        if(path==3){
            n++;
            path = 0;
        }
        ans++;
    }
    cout << ans << endl;
}