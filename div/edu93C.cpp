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
const int N = 1e5 + 50;
int t;
int n;

int main()
{
    cin >> t;

    while (t--) {
        cin >> n;

        string s;
        cin >> s;
        vector<ll> a;
        ll sum = 0;
        a.push_back(0);
        for (int i = 0; i < n; i++) {
            sum += s[i] - '1';
            a.push_back(sum);
        }
        sum = 0;
        ll res = 0;
        for (int i = 0; i <= n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        for (int i = 0; i <= n; i++) {
            if (a[i] == 0) {
                sum++;
            } else {
                res += sum * (sum - 1) / 2;
                sum = 0;
            }
        }
        cout << sum << endl;
    }
}