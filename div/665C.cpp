#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <string.h>
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
int a[N], b[N];

int main()
{
    cin >> t;
    while (t--) {
        cin >> n;
        int minN = 1e9 + 50;
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            b[i] = a[i];
            if (a[i] < minN)
                minN = a[i];
        }
        sort(a, a + n);
        bool flag = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i])
                continue;
            else if (b[i] % minN != 0) {
                flag = 1;
                break;
            }
        }

        if (!flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}