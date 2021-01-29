#include <bits/stdc++.h>
using namespace std;
#define trace1(x) cerr << #x << ": " << x << "\n";
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << "\n";
#define trace3(x, y, z) cerr << #x << ":" << x << " | " << #y << ": " << y << " | " << #z << ": " << z << "\n";
#define trace4(a, b, c, d) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << "\n";
#define trace5(a, b, c, d, e) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << "\n";
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << "\n";
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define N 1e6 + 5

int main()
{
    IOS int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        for (int i = 0; i < n; ++i) {
            bool ok = 0;
            if (arr[i] >= 10 * d) {
                cout << "YES\n";
                continue;
            }
            while (arr[i] > 0) {
                arr[i] -= d;
                if (arr[i] % 10 == 0) {
                    ok = 1;
                    break;
                }
            }
            if (ok) {
                cout << "YES\n";
            } else {
                cout << "NO"
                     << "\n";
            }
        }
    }
    return 0;
}
