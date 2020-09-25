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
int n;
int st[N];
void add(int x)
{
    int Bit = 0;
    while (x) {
        x >>= 1;
        Bit++;
    }
    st[Bit]++;
}

int main()
{
    cin >> t;
    while(t--){
        memset(st, 0, sizeof st);
        cin >> n;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            add(x);
        }
        ll ans = 0;
        for (int i = 0; i <= 32; i++) {
            if(st[i]>=2){
                int s = st[i];
                ans += s * (s - 1) / 2;
            }
        }
        cout << ans << endl;
    }
}