#include "iostream"
using namespace std;

typedef unsigned long long ull;
const int N = 30, P = 131;
int n;
string s[N];
int ju[N];
int maxN=1,maxN2;
string ans;
int ll = 0;
int judge(string a,string b)
{
    int t = min(a.size(), b.size());
    int h = a.size();
    bool flag = 0;
    int len = 0;
    ull hs=0, ha=0, p=1;
    for (int i = 0; i < t;i++)
    {
        hs = hs * P + b[i];
        ha = ha + a[h-i-1] * p;
        p *= P;
        if(ha==hs)
        {
            ll++;
            len = i+1;
            flag = 1;
            break;
        }
    }
    if(flag)
            return len;
    else
        return 0;
}


void dfs(string a,int lennow)
{
    maxN = max(lennow, maxN);
    for (int i = 0; i < n;i++)
    {
        if(ju[i]>=2)
            continue;
        int c = judge(a, s[i]);
        if(c>0)
        {
            ju[i]++;
            dfs(s[i], lennow + s[i].size() - c);
            ju[i]--;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i <= n;i++)
        cin >> s[i];
    dfs(s[n],1);
    cout << maxN << endl;

    // string l, k;
    // cin >> l >> k;
    // cout << judge(l, k);
}
