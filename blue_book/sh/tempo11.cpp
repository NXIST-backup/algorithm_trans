#include <iostream>
using namespace std;
typedef unsigned long long LL;
const LL MOD = 1000000007;
int main()
{
    LL n, ans = 1, now = 2;
    cin >> n;
    n--;
    while (n) {
        //cout<<"now: "<<now<<endl;
        if (n & 1) {
            // cout<<"ok"<<endl;
            ans = (ans * now) % MOD;
        }
        now = (now * now) % MOD;
        n >>= 1;
        // cout<<"ans: "<<ans<<endl;
    }
    cout << ans << endl;
    return 0;
}