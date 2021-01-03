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

const int N = 1e5 + 50;

int t;
int st[N];

int main()
{
    cin >> t;

    while (t--) {

        int n;
        int res = 0;
        cin >> n;
        memset(st, 0, sizeof st);
        for (int i = 1; i <= n;i++)
        {
            int k;
            int flag = 0;
            cin >> k;
            for (int j = 0; j < k;j++)
            {
                int x;
                cin >> x;
                if(!st[x]&&!flag)
                    st[x] = 1,flag=1;
            }
            if(!flag)
                res = i;
        }
        bool flag2 = 0;
        for (int i = 1; i <= n;i++)
        {
            if(!st[i])
            {
                cout << "IMPROVE" << endl;
                cout << res << " " << i << endl;
                flag2 = 1;
                break;
            }
        }
        if(!flag2)
            cout << "OPTIMAL" << endl;
    }
}