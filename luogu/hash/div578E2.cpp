#include "cstring"
#include "iostream"
using namespace std;

typedef unsigned long long ull;

const int N = 1000050, P = 131,P2=127;
const ull mod1 = 1e9 + 8;
string s, ans;
int n;
ull hs, ha,p,p2;
ull hs1, ha1;

int main()
{
    cin >> n;
    cin >> ans;
    n--;
    while(n--){
        cin >> s;
        int ls = s.size();
        //cout << ls << " ";
        int la = ans.size();
        //cout << la << endl;
        int x = min(ls, la);
        int t = 0;
        p = 1;
        p2 = 1;
        ha = 0;
        hs = 0;
        hs1 = 0;
        ha1 = 0;
        for (int i = 0; i < x;i++)
        {
            hs = hs * P + s[i];
            hs1 = ((hs1 * P2)%mod1 + s[i])%mod1;
            ha = ha + ans[la-i-1] * p;
            ha1 =(ha1 + (ans[la-i-1] * p2)%mod1)%mod1;
            if(hs==ha&&ha1==hs1)
                t = i + 1;
            p = p * P;
            p2 = p2 * P2%mod1;
        }
        ans += s.substr(t);
    }
    cout << ans << endl;

}