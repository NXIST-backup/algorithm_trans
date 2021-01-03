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
typedef pair<int, int> pii;

int t;
int n;

int main()
{
    cin >> t;
    while (t--) {
        cin >> n;
        int flag = 0;
        cin >> flag;
        ll res = 0;
        for (int i = 1; i < n; i++) {
            int x;
            cin >> x;
            if (x < flag) {
                res += flag - x;
                flag = x;
            } else {
                flag = x;
            }
        }
        cout << res << endl;
    }
}