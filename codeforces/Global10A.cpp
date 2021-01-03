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

        vector<int> a;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;

            a.push_back(x);
        }

        sort(a.begin(), a.end());

        if (a[0] == a[n - 1])
            cout << n << endl;
        else
            cout << 1 << endl;

    }


}