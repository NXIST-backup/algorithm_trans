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
        string ls;
        cin >> ls;
        int flag=0;
        for (int i = 0; i < n; i++) {
            if (ls[0] != ls[i]) {
                flag = i;
                break;
            }
        }
        for (int i = 0; i < flag; i++) {
            ls.push_back(ls[i]);
        }
        if (!flag) {
            if (n <= 2) {
                cout<<0<<endl;
            }else {
                cout << n / 3 + bool(n % 3 > 0)<<endl;
            }
        } else {
            ll cnt=1,ans=0;
            for (int i = flag; i < n + flag; i++) {
                if (ls[i] != ls[i + 1]) {
                    ans += cnt / 3;
                    cnt = 1;
                }else {
                    cnt++;
                }
            }
            cout << ans << endl;
        }
    }

}