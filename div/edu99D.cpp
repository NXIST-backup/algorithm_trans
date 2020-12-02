//贪心
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

int t;
int n, x;
int a[505];
int b[505];

int main()
{
    cin >> t;

    while (t--) {
        cin >> n >> x;

        for (int i = 1; i <= n; i++)
            cin >> a[i], b[i] = a[i];

        sort(a + 1, a + n + 1);
        bool flag = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] != b[i]) {
                flag = 1;
                break;
            }
        }
        int tmp = x;
        int pos = 0;
        for (int i = n; i >= 2; i--) {
            if (b[i] < b[i - 1]) {
                pos = i - 1;
                break;
            }
        }
        if (!flag) {
            cout << 0 << endl;
            continue;
        }
        int cnt = 0;
        //cout << pos << " ";
        for (int i = 1; i <= n; i++) {
            if (x < b[i] && i <= pos) {
                swap(x, b[i]);
                cnt++;
            }
            if (i > pos && b[i + 1] < b[i] && i < n) {
                swap(x, b[i]);
                cnt++;
            }
            a[i] = b[i];
        }
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++) {
            if (a[i] != b[i]) {
                flag = 0;
                break;
            }
        }

        if (flag)
            cout << cnt << endl;
        else
            cout << -1 << endl;
    }
}