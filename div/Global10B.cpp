#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e9;
typedef pair<int, int> pii;

int t,n;
ll k;

int main()
{
    cin >> t;

    while (t--) {
        cin >> n >> k;
        vector<ll> a;
        int maxN = -1e9 - 10;
        int flag = 0,flag2=0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x < 0 && flag == 0)
                flag = 1;
            if (x == 0 &&flag == 0)
                flag2=1;
            if (x > maxN)
                maxN = x;
            a.push_back(x);
        }
        if (flag2 == 0 && flag == 0)
            flag = 1;
        vector<ll> b;
        int maxN2 = -1e9 - 20;
        if (flag == 1) {
            for (int i = 0; i < n; i++) {
                a[i] = maxN - a[i];
                if (maxN2 < a[i])
                    maxN2 = a[i];
            }
            for (int i = 0; i < n; i++) {
                b.push_back(maxN2 - a[i]);
            }
        } else {
            for (int i = 0; i < n; i++) {
                int x = maxN - a[i];
                b.push_back(x);
                if (maxN2 < x)
                    maxN2 = x;
            }
        }

        if (k % 2) {
            for (auto item : a) {
                cout << item << " ";
            }
            cout << endl;
        } else {
            for (auto item : b) {
                cout << item << " ";
            }
            cout << endl;
        }
    }
}