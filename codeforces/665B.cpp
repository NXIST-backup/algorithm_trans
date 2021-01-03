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

int t;

int main()
{
    cin >> t;

    while (t--) {

        vector<int> a, b;
        for (int i = 0; i < 3;i++){
            int x;
            cin >> x;
            a.push_back(x);
        }
        for (int i = 0; i < 3;i++){
            int x;
            cin >> x;
            b.push_back(x);
        }

        ll res = 0;

        if(a[2]!=0&&b[1]!=0){
            int temp = min(a[2], b[1]);
            res += 2 * temp;
            a[2] -= temp;
            b[1] -= temp;
        }
        if(a[2]!=0&&b[2]!=0){
            int temp = min(a[2], b[2]);
            a[2] -= temp;
            b[2] -= temp;
        }
        if(b[2]!=0&&a[0]!=0){
            int temp = min(b[2], a[0]);
            b[2] -= temp;
            a[0] -= temp;
        }
        if(b[2]!=0&&a[1]!=0){
            int temp = min(b[2], a[1]);
            res += temp * -2;
            b[2] -= temp;
            a[1] -= temp;
        }

        cout << res << endl;
    }
}