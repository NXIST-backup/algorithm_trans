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
        int x, y;
        cin >> x >> y;

        if(abs(x-y)<=1)
            cout << x + y << endl;
        else{
            int res = 0;
            int x1 = max(x, y), y1 = min(x, y);
            while(x1-y1>1){
                x1--;
                res+=2;
            }
            res += x1 + y1;
            cout << res << endl;
        }
    }
}