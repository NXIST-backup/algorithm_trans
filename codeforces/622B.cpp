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

int t;

int main()
{
    cin >> t;
    while (t--) {

        int n, x, y;
        cin >> n >> x >> y;

        int mins = 0, maxs = 0;
        if(x+y>n)
            mins = n;
        else
            mins = min(x + y - 1, n);

        if(x+y<=n)
            maxs = 1;
        else
            maxs= min(x + y - n + 1, n);

        cout << maxs << " " << mins << endl;
    }
}