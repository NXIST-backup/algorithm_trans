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
ll p, f, cnts, cntw, s, w;
int main()
{
    cin >> t;
    while (t--) {
        cin >> p >> f >> cnts >> cntw >> s >> w;
        if(s<w){
            swap(s, w);
            swap(cnts, cntw);
        }
        ll sum = p + f;
        ll numw = min(sum / w, cntw);
        ll nums = min((sum - numw * w) / s, cnts);
        ll nums2 = min(nums,  p/ s);
        ll res = 0;
        for (ll i = 0; i <= nums2;i++){
            ll a = i;
            ll b = min((p - i * s) / w, numw);
            ll c = min(f / s, nums - i);
            ll d = min((f - c * s) / w, numw - b);
            res = max(a + b + c + d, res);
        }
        cout << res << endl;
    }
}