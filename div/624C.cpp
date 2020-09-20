//差分


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

const int N = 2e5 + 50;

int t;

int n, m;

int p[N];
int res[144];
int main()
{
    cin >> t;
    while (t--) {

        cin >> n >> m;

        string a;

        cin >> a;
        memset(res, 0, sizeof res);
        memset(p, 0, sizeof p);
        for (int i = 1; i <= m;i++)
        {
            int x;
            cin >> x;
            p[0]++, p[x]--;
        }
        p[0]++, p[n]--;
        for (int i = 0; i < n;i++)
        {
            res[a[i]] += p[i];
            p[i + 1] += p[i];
        }

        for (int i = 'a'; i <= 'z';i++)
            cout << res[i] << " ";

        cout << endl;
    }
}
